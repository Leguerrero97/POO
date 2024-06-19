#include "login.h"
#include <QPainter>
#include <QDebug>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QTimer>
#include <QSettings>
#include <QStandardPaths>

Login::Login(QWidget *parent) : QWidget(parent), intentosFallidos(0), imagenActualizada(false) {
    QGridLayout *layout = new QGridLayout(this);

    QLabel *usernameLabel = new QLabel("Usuario:", this);
    usernameField = new QLineEdit(this);

    QLabel *passwordLabel = new QLabel("Clave:", this);
    passwordField = new QLineEdit(this);
    passwordField->setEchoMode(QLineEdit::Password);
    connect(passwordField, &QLineEdit::returnPressed, this, &Login::onPasswordReturnPressed);

    loginButton = new QPushButton("Login", this);
    connect(loginButton, &QPushButton::clicked, this, &Login::handleLogin);

    toggleButton = new QPushButton("Mostrar/Ocultar Temperatura", this);
    connect(toggleButton, &QPushButton::clicked, this, &Login::toggleTemperatureDisplay);

    layout->addWidget(usernameLabel, 0, 0);
    layout->addWidget(usernameField, 0, 1);
    layout->addWidget(passwordLabel, 1, 0);
    layout->addWidget(passwordField, 1, 1);
    layout->addWidget(loginButton, 2, 0, 1, 2);
    layout->addWidget(toggleButton, 3, 0, 1, 2);

    temperaturaLabel = new QLabel("Temperatura: -- °C", this);
    temperaturaVisible = false;
    temperaturaLabel->hide();
    layout->addWidget(temperaturaLabel, 4, 0, 1, 2);

    setLayout(layout);

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Login::slot_descargaFinalizada);

    QString sUrl = "https://static.vecteezy.com/system/resources/thumbnails/007/510/254/small_2x/1960s-hippie-style-wallpaper-design-trippy-retro-background-for-psychedelic-60s-70s-parties-with-bright-melting-rainbow-colors-and-groovy-wavy-pattern-in-pop-art-style-outline-illustration-vector.jpg";
    networkManager->get(QNetworkRequest(QUrl(sUrl)));

    QString ciudad = "Cordoba";
    QString apiKey = "9febec5736512a80b54c1089097ff939";
    QString apiUrl = QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric").arg(ciudad).arg(apiKey);
    networkManager->get(QNetworkRequest(QUrl(apiUrl)));

    // Leer el estado de bloqueo desde QSettings al iniciar (usa la ruta del archivo)
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/config.ini";
    QSettings settings(configPath, QSettings::IniFormat);
    if (settings.value("bloqueado", false).toBool()) {
        QDateTime tiempoBloqueo = settings.value("tiempoBloqueo").toDateTime();
        int tiempoRestante = tiempoBloqueo.secsTo(QDateTime::currentDateTime());
        if (tiempoRestante > 0) {
            loginButton->setEnabled(false);
            QTimer::singleShot(tiempoRestante * 1000, this, &Login::habilitarLogin);
            QMessageBox::warning(this, "Bloqueado",
                                QString("Demasiados intentos fallidos. Bloqueado por %1 segundos.").arg(tiempoRestante));
        } else {
            settings.remove("bloqueado");
            settings.remove("tiempoBloqueo");
        }
    }
}

Login::~Login() {
    delete networkManager;
}

void Login::handleLogin() {
    QString username = usernameField->text();
    QString password = passwordField->text();

    if (username == "admin" && password == "1111") {
        Formulario *form = new Formulario();
        form->show();
        close();
        intentosFallidos = 0;
    } else {
        intentosFallidos++;
        if (intentosFallidos >= 3) {
            QMessageBox::warning(this, "Bloqueado", "Demasiados intentos fallidos. Bloqueado por 5 minutos.");
            loginButton->setEnabled(false);
            QTimer::singleShot(300000, this, &Login::habilitarLogin);

            // Guardar el estado de bloqueo en el archivo de configuración
            QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/config.ini";
            QSettings settings(configPath, QSettings::IniFormat);
            settings.setValue("bloqueado", true);
            settings.setValue("tiempoBloqueo", QDateTime::currentDateTime().addSecs(300));
        } else {
            QMessageBox::warning(this, "Error", "Clave incorrecta");
            passwordField->clear();
        }
    }
}

void Login::slot_descargaFinalizada(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        if (reply->url().toString().contains("vecteezy.com")) {
            backgroundImage = QImage::fromData(reply->readAll());
            if (!backgroundImage.isNull()) {
                imagenActualizada = true;
                update();
                show(); // <-- Mostrar la ventana después de cargar la imagen
            } else {
                qDebug() << "Error cargando imagen de fondo.";
                QMessageBox::critical(this, "Error", "Error al cargar la imagen de fondo.");
            }
        } else {
            QByteArray respuesta = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(respuesta);
            QJsonObject jsonObject = jsonResponse.object();
            if (jsonObject.contains("main")) {
                QJsonObject main = jsonObject["main"].toObject();
                if (main.contains("temp")) {
                    double temperatura = main["temp"].toDouble();
                    mostrarTemperatura(temperatura);
                }
            }
        }
    } else {
        qDebug() << "Error cargando recurso:" << reply->errorString();
        QMessageBox::critical(this, "Error", "Error al cargar recurso.");
    }
    reply->deleteLater();
}

void Login::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    if (!backgroundImage.isNull() && imagenActualizada) {
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.drawImage(rect(), backgroundImage.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Escalamos la imagen para que se ajuste a la ventana
    }
}

void Login::onPasswordReturnPressed() {
    handleLogin();
}

void Login::showBackground() {
    // Este método ya no es necesario
}

void Login::mostrarTemperatura(double temperatura) {
    temperaturaLabel->setText(QString("Temperatura: %1 °C").arg(temperatura));
    if (!temperaturaVisible) {
        temperaturaVisible = true;
        temperaturaLabel->show();
    }
}

void Login::toggleTemperatureInfo() {
    temperaturaVisible = !temperaturaVisible;
    temperaturaLabel->setVisible(temperaturaVisible);
}

void Login::toggleTemperatureDisplay() {
    toggleTemperatureInfo();
}

void Login::habilitarLogin() {
    loginButton->setEnabled(true);
    intentosFallidos = 0;

    // Eliminar la información de bloqueo del archivo de configuración
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/config.ini";
    QSettings settings(configPath, QSettings::IniFormat);
    settings.remove("bloqueado");
    settings.remove("tiempoBloqueo");
}
