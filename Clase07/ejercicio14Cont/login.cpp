#include "login.h"
#include "formulario.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPainter>
#include <QDebug>

Login::Login(QWidget *parent) : QWidget(parent), isTempVisible(true) {
    QGridLayout *layout = new QGridLayout(this);

    QLabel *usernameLabel = new QLabel("Usuario:", this);
    usernameField = new QLineEdit(this);

    QLabel *passwordLabel = new QLabel("Clave:", this);
    passwordField = new QLineEdit(this);
    passwordField->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);
    connect(loginButton, &QPushButton::clicked, this, &Login::handleLogin);

    layout->addWidget(usernameLabel, 0, 0);
    layout->addWidget(usernameField, 0, 1);
    layout->addWidget(passwordLabel, 1, 0);
    layout->addWidget(passwordField, 1, 1);
    layout->addWidget(loginButton, 2, 0, 1, 2);

    temperatureLabel = new QLabel(this);
    layout->addWidget(temperatureLabel, 3, 0, 1, 2);

    toggleTempButton = new QPushButton("Mostrar/Ocultar Temperatura", this);
    connect(toggleTempButton, &QPushButton::clicked, this, &Login::toggleTemperatureDisplay);
    layout->addWidget(toggleTempButton, 4, 0, 1, 2);

    setLayout(layout);

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Login::backgroundImageDownloaded);

    fetchTemperature();
    setBackgroundImage(QUrl("https://upload.wikimedia.org/wikipedia/commons/4/4e/Vel%C3%A1zquez_-_de_Breda_o_Las_Lanzas_%28Museo_del_Prado%2C_1634-35%29.jpg"));
}

Login::~Login() {
    delete networkManager;
}

void Login::fetchTemperature() {
    QNetworkRequest request(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Cordoba,AR&appid=9febec5736512a80b54c1089097ff939&units=metric"));
    networkManager->get(request);
}

void Login::displayTemperature(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDoc.object();
        double temp = jsonObject["main"].toObject()["temp"].toDouble();
        temperatureLabel->setText(QString("Temperatura en Córdoba: %1°C").arg(temp));
    } else {
        temperatureLabel->setText("Error al obtener la temperatura");
    }
    reply->deleteLater();
}

void Login::toggleTemperatureDisplay() {
    isTempVisible = !isTempVisible;
    temperatureLabel->setVisible(isTempVisible);
}

void Login::handleLogin() {
    QString username = usernameField->text();
    QString password = passwordField->text();

    if (username == "admin" && password == "1111") {
        this->close();
        Formulario *form = new Formulario();
        form->show();
    } else {
        QMessageBox::warning(this, "Error", "Clave incorrecta");
        passwordField->clear();
    }
}

void Login::setBackgroundImage(const QUrl &url) {
    QNetworkRequest request(url);
    networkManager->get(request);
}

void Login::backgroundImageDownloaded(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray imageData = reply->readAll();
        backgroundImage.loadFromData(imageData);
        update(); // Redibujar el widget para mostrar la imagen de fondo
    } else {
        qDebug() << "Error loading background image:" << reply->errorString();
    }
    reply->deleteLater();
}

void Login::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    if (!backgroundImage.isNull()) {
        painter.setRenderHint(QPainter::SmoothPixmapTransform); // Para suavizar el escalado
        painter.drawImage(rect(), backgroundImage.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
}


