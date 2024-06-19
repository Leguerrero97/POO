/login.cpp
#include "login.h"
#include "formulario.h"
#include <QPainter>
#include <QNetworkRequest>
#include <QUrl>
#include <QFile>
#include <QBuffer>

Login::Login(QWidget *parent) : QWidget(parent) {
    QLabel *labelUsuario = new QLabel("Usuario:");
    lineEditUsuario = new QLineEdit;
    QLabel *labelClave = new QLabel("Clave:");
    lineEditClave = new QLineEdit;
    lineEditClave->setEchoMode(QLineEdit::Password);
    QPushButton *buttonIngresar = new QPushButton("Ingresar");
    buttonMostrarTemperatura = new QPushButton("Mostrar Temperatura");
    labelTemperatura = new QLabel("Temperatura: ");
    labelTemperatura->setVisible(false); // Inicialmente ocultamos la temperatura

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(labelUsuario, 0, 0);
    layout->addWidget(lineEditUsuario, 0, 1);
    layout->addWidget(labelClave, 1, 0);
    layout->addWidget(lineEditClave, 1, 1);
    layout->addWidget(buttonIngresar, 2, 0, 1, 2);
    layout->addWidget(buttonMostrarTemperatura, 3, 0, 1, 2);
    layout->addWidget(labelTemperatura, 4, 0, 1, 2);

    setLayout(layout);

    connect(lineEditClave, SIGNAL(returnPressed()), this, SLOT(verificarClave()));
    connect(buttonIngresar, SIGNAL(clicked()), this, SLOT(verificarClave()));
    connect(buttonMostrarTemperatura, SIGNAL(clicked()), this, SLOT(toggleTemperatura()));

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Login::slot_descargaFinalizada);

    // Obtener la temperatura al inicio
    obtenerTemperatura();
}

void Login::verificarClave() {
    QString usuario = "admin";
    QString clave = "1111";

    if (lineEditUsuario && lineEditClave) {
        if (lineEditUsuario->text() == usuario && lineEditClave->text() == clave) {
            // Si el usuario y la clave son correctos, cerramos el Login y mostramos el Formulario
            Formulario *formulario = new Formulario;
            formulario->show();
            close();
        } else {
            // Si el usuario o la clave son incorrectos, borramos el texto de los campos correspondientes
            lineEditUsuario->clear();
            lineEditClave->clear();
        }
    }
}

void Login::toggleTemperatura() {
    labelTemperatura->setVisible(!labelTemperatura->isVisible());
}

void Login::obtenerTemperatura() {
    QUrl url("http://api.openweathermap.org/data/2.5/weather?q=Cordoba&appid=9febec5736512a80b54c1089097ff939");
    QNetworkRequest request(url);
    manager->get(request);
}

void Login::slot_descargaFinalizada(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonResponse.object();
        double temperatura = jsonObject["main"].toObject()["temp"].toDouble() - 273.15; // Convertir de Kelvin a Celsius
        labelTemperatura->setText(QString("Temperatura: %1 °C").arg(temperatura));
    } else {
        qDebug() << "Error al obtener la temperatura:" << reply->errorString();
    }
    reply->deleteLater();
}
