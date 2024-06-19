#include "ventana.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QNetworkRequest>

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    urlLineEdit = new QLineEdit(this);
    connect(urlLineEdit, &QLineEdit::returnPressed, this, &Ventana::onUrlEntered);
    layout->addWidget(urlLineEdit);

    fetchButton = new QPushButton("Obtener HTML", this);
    connect(fetchButton, &QPushButton::clicked, this, &Ventana::onUrlEntered);
    layout->addWidget(fetchButton);

    htmlTextEdit = new QTextEdit(this);
    htmlTextEdit->setReadOnly(true);
    layout->addWidget(htmlTextEdit);

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Ventana::onHtmlDownloaded);
}

Ventana::~Ventana() {
    delete networkManager;
}

void Ventana::onUrlEntered() {
    QString url = urlLineEdit->text();
    networkManager->get(QNetworkRequest(QUrl(url)));
}

void Ventana::onHtmlDownloaded(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QString html = reply->readAll();
        htmlTextEdit->setText(html);
    } else {
        QMessageBox::critical(this, "Error", "Error al descargar HTML.");
    }
}
