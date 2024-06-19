#include "mainwindow.h"
#include "ui_parser.h" // Incluimos el archivo generado por Qt Designer para parser.ui

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PARSER) // Usamos la clase Ui::PARSER generada desde parser.ui
{
    ui->setupUi(this); // Configuramos la interfaz de usuario

    parser = new Parser(this);
    downloader = new Downloader(this);
    imageWidget = new ImageWidget(this);

    // Conectamos los botones a sus respectivos slots
    connect(ui->pbDescargar, &QPushButton::clicked, this, &MainWindow::onDownloadButtonClicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onChooseImageButtonClicked);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::onNetworkReplyFinished);
    connect(downloader, &Downloader::downloadFinished, this, &MainWindow::onResourceDownloadFinished);
    connect(downloader, &Downloader::allDownloadsFinished, this, &MainWindow::onAllDownloadsFinished);
    connect(downloader, &Downloader::downloadProgress, this, &MainWindow::onDownloadProgress);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onDownloadButtonClicked() {
    QString urlString = ui->urlLineEdit->text();
    if (urlString.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor, ingrese una URL válida.");
        return;
    }

    if (downloadDirectory.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor, seleccione un directorio de descarga.");
        return;
    }

    QUrl url(urlString);
    if (!url.isValid()) {
        QMessageBox::warning(this, "Error", "La URL ingresada no es válida.");
        return;
    }

    QNetworkRequest request(url);
    htmlReply = networkManager->get(request);
    connect(htmlReply, &QNetworkReply::downloadProgress, this, &MainWindow::onDownloadProgress);
    ui->logTextEdit->append("Descargando HTML...");
}

void MainWindow::onChooseDirectoryButtonClicked() {
    downloadDirectory = QFileDialog::getExistingDirectory(this, "Seleccionar directorio de descarga");
    if (!downloadDirectory.isEmpty()) {
        ui->logTextEdit->append("Directorio de descarga seleccionado: " + downloadDirectory);
    }
}

void MainWindow::onChooseImageButtonClicked() {
    QString imagePath = QFileDialog::getOpenFileName(this, "Seleccionar imagen", "", "Imágenes (*.png *.xpm *.jpg)");
    if (!imagePath.isEmpty()) {
        imageWidget->loadImage(imagePath);
    }
}

void MainWindow::onNetworkReplyFinished(QNetworkReply *reply) {
    if (reply == htmlReply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray htmlContent = reply->readAll();
            QVector<QUrl> urls = parser->parseHtmlForUrls(htmlContent);
            totalResources = urls.size();
            downloadedResources = 0;
            downloadResources(urls);
        } else {
            QMessageBox::warning(this, "Error", "Error al descargar el HTML: " + reply->errorString());
        }
        reply->deleteLater();
        htmlReply = nullptr;
    }
}

void MainWindow::downloadResources(const QVector<QUrl> &urls) {
    for (const QUrl &url : urls) {
        QString filePath = downloadDirectory + "/" + QFileInfo(url.path()).fileName();
        downloader->download(url, filePath);
    }
}

void MainWindow::onResourceDownloadFinished(const QUrl &url, bool success) {
    if (success) {
        ui->logTextEdit->append("Descargado: " + url.toString());
    } else {
        ui->logTextEdit->append("Error al descargar: " + url.toString());
    }

    downloadedResources++;
    int progress = (downloadedResources * 100) / totalResources;
    ui->progressBar->setValue(progress);

    if (downloadedResources == totalResources) {
        onAllDownloadsFinished();
    }
}

void MainWindow::onAllDownloadsFinished() {
    ui->logTextEdit->append("Todas las descargas finalizaron.");
    ui->progressBar->setValue(100);
}

void MainWindow::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal) {
    if (bytesTotal > 0) {
        int percent = static_cast<int>((bytesReceived * 100) / bytesTotal);
        ui->progressBar->setValue(percent);
    }
}
