#include "admindb.h"
#include <QDebug>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>

AdminDB::AdminDB(QObject *parent)
    : QObject(parent), loginValido(false) {
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &AdminDB::handleLoginResponse);
}

AdminDB::~AdminDB() {
    delete networkManager;
}

bool AdminDB::validarUsuario(const QString &usuario, const QString &clave) {
    QUrlQuery postData;
    postData.addQueryItem("username", usuario);
    postData.addQueryItem("password", clave);

    QNetworkRequest request(QUrl(endpointUrl));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    networkManager->post(request, postData.toString().toUtf8());

    // Espera la respuesta de FastAPI usando un QEventLoop
    eventLoop.exec();

    return loginValido;
}

void AdminDB::handleLoginResponse(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonResponse.object();

        // Verifica la respuesta JSON (ajusta según la estructura de tu respuesta)
        if (jsonObject.contains("status") && jsonObject["status"].toString() == "success") {
            loginValido = true;
        } else {
            loginValido = false;
        }
    } else {
        qDebug() << "Error en la solicitud de red:" << reply->errorString();
        loginValido = false;
    }

    // Sale del QEventLoop
    eventLoop.quit();
    reply->deleteLater();
}
