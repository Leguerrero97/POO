#include "login.h"
#include "ventana.h"
#include <QMessageBox>
#include <QPainter>
#include <QDebug>
#include <QNetworkRequest>

Login::Login(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);

    QLabel *usernameLabel = new QLabel("Usuario:", this);
    usernameField = new QLineEdit(this);

    QLabel *passwordLabel = new QLabel("Clave:", this);
    passwordField = new QLineEdit(this);
    passwordField->setEchoMode(QLineEdit::Password);
    connect(passwordField, &QLineEdit::returnPressed, this, &Login::onPasswordReturnPressed);

    loginButton = new QPushButton("Login", this);
    connect(loginButton, &QPushButton::clicked, this, &Login::handleLogin);

    layout->addWidget(usernameLabel, 0, 0);
    layout->addWidget(usernameField, 0, 1);
    layout->addWidget(passwordLabel, 1, 0);
    layout->addWidget(passwordField, 1, 1);
    layout->addWidget(loginButton, 2, 0, 1, 2);

    setLayout(layout);

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Login::slot_descargaFinalizada);
    connect(this, &Login::backgroundLoaded, this, &Login::show); // Conectar señal a slot

    QString sUrl = "https://wallpapers.net/web/wallpapers/lamp-at-the-wall-hd-wallpaper/400x400.jpg";
    networkManager->get(QNetworkRequest(QUrl(sUrl)));
}

Login::~Login() {
    delete networkManager;
}

void Login::handleLogin() {
    QString username = usernameField->text();
    QString password = passwordField->text();

    if (username == "admin" && password == "1111") {
        Ventana *form = new Ventana();
        form->show();
        close();
    } else {
        QMessageBox::warning(this, "Error", "Clave incorrecta");
        passwordField->clear();
    }
}

void Login::slot_descargaFinalizada(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        backgroundImage = QImage::fromData(reply->readAll());
        if (!backgroundImage.isNull()) {
            resize(backgroundImage.size());
            emit backgroundLoaded(); // Emitir señal cuando la imagen está lista
            update();
        }
    } else {
        qDebug() << "Error loading background image:" << reply->errorString();
        // Aquí podrías agregar un mensaje de error para el usuario
    }
    reply->deleteLater();
}

void Login::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    if (!backgroundImage.isNull()) {
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.drawImage(rect(), backgroundImage.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void Login::onPasswordReturnPressed() {
    handleLogin();
}
