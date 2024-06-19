#include "ventana.h"
#include "ui_ventana.h"
#include <QPainter>
#include <QNetworkRequest>

Ventana::Ventana(QWidget *parent) : QWidget(parent),
                                    ui(new Ui::Ventana),
                                    manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    connect(manager, &QNetworkAccessManager::finished, this, &Ventana::slot_descargaFinalizada);

    QString sUrl = "https://img.freepik.com/foto-gratis/pintura-lago-montana-montana-al-fondo_188544-9126.jpg";
    manager->get(QNetworkRequest(QUrl(sUrl)));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if (!im.isNull()) {
        painter.drawImage(rect(), im.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void Ventana::slot_descargaFinalizada(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        im = QImage::fromData(reply->readAll());
        if (!im.isNull()) {
            // Ajustar el tamaño de la ventana al tamaño de la imagen
            resize(im.size());
            update(); // Redibujar el widget para mostrar la imagen
        }
    }
    reply->deleteLater();
}

