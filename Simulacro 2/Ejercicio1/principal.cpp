#include "principal.h"
#include "ui_principal.h"
#include <QPainter>
#include <QSqlQuery>
#include <QDebug>

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    setFixedSize(300, 300);

    if (AdminDB::instance().conectar("C:/Users/Lautaro/Documents/Qt/Simulacro 2/Ejercicio1/rectangles.sqlite")) {
        qDebug() << "Conexion exitosa";
        cargarRectangulos();
    } else {
        qDebug() << "Conexion NO exitosa";
    }
}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    for (const Rectangulo &rect : rectangulos) {
        painter.drawRect(rect.getX(), rect.getY(), rect.getAncho(), rect.getAlto());
    }
}

void Principal::cargarRectangulos()
{
    QSqlQuery query = AdminDB::instance().select("SELECT x, y, ancho, alto FROM rectangulos;");
    while (query.next()) {
        int x = query.value(0).toInt();
        int y = query.value(1).toInt();
        int ancho = query.value(2).toInt();
        int alto = query.value(3).toInt();

        rectangulos.append(Rectangulo(x, y, ancho, alto));
    }
}

