#include "ventana.h"
#include "ui_ventana.h"
#include "boton.h"
#include <QPainter>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // Conectar la señal signal_clic() de cada botón al slot handleButtonClick()
    connect(findChild<Boton*>("pushButton"), &Boton::signal_clic, this, &Ventana::handleButtonClick);
    connect(findChild<Boton*>("pushButton_2"), &Boton::signal_clic, this, &Ventana::handleButtonClick);
    connect(findChild<Boton*>("pushButton_3"), &Boton::signal_clic, this, &Ventana::handleButtonClick);
    connect(findChild<Boton*>("pushButton_4"), &Boton::signal_clic, this, &Ventana::handleButtonClick);
    connect(findChild<Boton*>("pushButton_5"), &Boton::signal_clic, this, &Ventana::handleButtonClick);

    // Conectar la señal de finalización de la descarga al slot correspondiente
    connect(networkManager, &QNetworkAccessManager::finished, this, &Ventana::onImageDownloaded);

    // Solicitar la imagen desde internet
    QUrl imageUrl("https://images.unsplash.com/photo-1548350896-fafc317d3ceb?q=80&w=2070&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D");
    QNetworkRequest request(imageUrl);
    networkManager->get(request);

    // Aplicar estilos para hacer los botones transparentes
    for (int i = 1; i <= 5; ++i) {
        QString buttonName = "pushButton_" + QString::number(i);
        Boton* button = findChild<Boton*>(buttonName);
        if (button) {
            button->setStyleSheet("background-color: transparent;");
        }
    }

    // Inicializar colores de los botones
    findChild<Boton*>("pushButton")->colorear(Boton::Rojo);
    findChild<Boton*>("pushButton_2")->colorear(Boton::Magenta);
    findChild<Boton*>("pushButton_3")->colorear(Boton::Azul);
    findChild<Boton*>("pushButton_4")->colorear(Boton::Verde);
    findChild<Boton*>("pushButton_5")->colorear(Boton::Azul);

    // Asignar textos a los botones
    findChild<Boton*>("pushButton")->setText("Mi Dentista");
    findChild<Boton*>("pushButton_2")->setText("Visitas");
    findChild<Boton*>("pushButton_3")->setText("Técnicas de higiene");
    findChild<Boton*>("pushButton_4")->setText("Mi Boca");
    findChild<Boton*>("pushButton_5")->setText("Hora de cepillarse");
}

Ventana::~Ventana()
{
    delete ui;
    delete networkManager; // Liberar el QNetworkAccessManager
}

void Ventana::handleButtonClick() {
    Boton *botonClicado = qobject_cast<Boton*>(sender());
    QString textoBoton = botonClicado->text();

    qDebug() << "Botón clicado: " << textoBoton;

    // Aquí puedes agregar acciones específicas para cada botón, por ejemplo:
    if (textoBoton == "Mi Dentista") {
        // ... hacer algo cuando se hace clic en "Mi Dentista"
    } else if (textoBoton == "Visitas") {
        // ... hacer algo cuando se hace clic en "Visitas"
    } // ... etc.
}

void Ventana::onImageDownloaded(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray imageData = reply->readAll();
        backgroundImage.loadFromData(imageData);
        update(); // Fuerza la actualización del widget para repintar el fondo
    } else {
        qDebug() << "Error descargando la imagen:" << reply->errorString();
    }
    reply->deleteLater();
}

void Ventana::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    if (!backgroundImage.isNull()) {
        painter.drawImage(rect(), backgroundImage);
    } else {
        // Dibujar un fondo de color sólido si la imagen no está disponible
        painter.fillRect(rect(), Qt::white);
    }
}
