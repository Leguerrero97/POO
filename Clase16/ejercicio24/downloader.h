// downloader.h
#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class Downloader : public QObject {
    Q_OBJECT

public:
    explicit Downloader(QObject *parent = nullptr);

public slots:
    void download(const QUrl &url, const QString &filePath);

signals:
    void downloadFinished(const QUrl &url, bool success);
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void allDownloadsFinished();

private slots:
    void onDownloadFinished(QNetworkReply *reply);
    void onDownloadProgress(qint64 bytesReceived, qint64 bytesTotal);

private:
    QNetworkAccessManager *networkManager;
};

#endif // DOWNLOADER_H
