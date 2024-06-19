// networkmanager.cpp
#include "networkmanager.h"

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void NetworkManager::crearUsuario(int legajo, const QString& nombre, const QString& apellido) {
    // Lógica para realizar la solicitud HTTP para crear un nuevo usuario
    QUrl url("http://localhost:8000/usuarios/");
    QUrlQuery query;
    query.addQueryItem("legajo", QString::number(legajo));
    query.addQueryItem("nombre", nombre);
    query.addQueryItem("apellido", apellido);
    QByteArray postData = query.toString(QUrl::FullyEncoded).toUtf8();

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkReply *reply = manager->post(request, postData);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            emit usuarioCreado();
        } else {
            qDebug() << "Error al crear usuario:" << reply->errorString();
        }
        reply->deleteLater();
    });
}
