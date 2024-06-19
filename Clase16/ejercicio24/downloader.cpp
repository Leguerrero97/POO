// downloader.cpp
#include "downloader.h"
#include <QFile>

Downloader::Downloader(QObject *parent) : QObject(parent) {
    networkManager = new QNetworkAccessManager(this);
}

void Downloader::download(const QUrl &url, const QString &filePath) {
    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, &Downloader::onDownloadFinished);
    connect(reply, &QNetworkReply::downloadProgress, this, &Downloader::onDownloadProgress);

    // Almacenar el reply para poder acceder a él en onDownloadFinished
    reply->setProperty("filePath", filePath);
}

void Downloader::onDownloadFinished(QNetworkReply *reply) {
    QString filePath = reply->property("filePath").toString();
    bool success = (reply->error() == QNetworkReply::NoError);

    if (success) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(reply->readAll());
            file.close();
        } else {
            success = false;
        }
    }

    emit downloadFinished(reply->url(), success);

    reply->deleteLater();

    // Verificar si todas las descargas han finalizado
    if (networkManager->activeDownloadCount() == 0) {
        emit allDownloadsFinished();
    }
}

void Downloader::onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal) {
    emit downloadProgress(bytesReceived, bytesTotal);
}
