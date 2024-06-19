#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QProgressBar>
#include "parser.h"
#include "downloader.h"
#include "imagewidget.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); // Destructor para liberar recursos

private slots:
    void onDownloadButtonClicked();
    void onChooseImageButtonClicked(); // Slot para el botón de elegir imagen
    void onNetworkReplyFinished(QNetworkReply *reply);
    void onResourceDownloadFinished(const QUrl &url, bool success);
    void onAllDownloadsFinished();
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void paintEvent(QPaintEvent *event) override; // Para dibujar la imagen

private:
    void downloadResources(const QVector<QUrl> &urls);

    ui::parser *ui; // Interfaz de usuario desde parser.ui
    Parser *parser;
    Downloader *downloader;
    ImageWidget *imageWidget;
    QNetworkAccessManager *networkManager;
    QNetworkReply *htmlReply;
    QString downloadDirectory;
    QString imagePath; // Ruta de la imagen seleccionada
    int totalResources;
    int downloadedResources;
};

#endif // MAINWINDOW_H

