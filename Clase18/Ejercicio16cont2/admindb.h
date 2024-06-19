#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>

class AdminDB : public QObject {
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr); // Constructor sin parámetros
    ~AdminDB();

    bool validarUsuario(const QString &usuario, const QString &clave);

private slots:
    void handleLoginResponse(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;
    QString endpointUrl = "http://127.0.0.1:8000/login"; // URL por defecto
    bool loginValido;
    QEventLoop eventLoop;
};

#endif // ADMINDB_H

