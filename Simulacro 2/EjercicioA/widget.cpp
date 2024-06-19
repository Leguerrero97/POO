// widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QSqlQuery>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    linea = nullptr; // Inicializar el puntero a nullptr

    if (adminDB.conectar("C:/Users/Lautaro/Documents/Qt/Simulacro 2/EjercicioA/dbA.sqlite3")) {
        qDebug() << "Conexion exitosa";

        // Leer los datos de la base de datos y crear el objeto Linea
        QSqlQuery query = adminDB.getDB().exec("SELECT x_inicial, y_inicial, x_final, y_final FROM lineas LIMIT 1;");
        if (query.next()) {
            int xInicial = query.value(0).toInt();
            int yInicial = query.value(1).toInt();
            int xFinal = query.value(2).toInt();
            int yFinal = query.value(3).toInt();

            linea = new Linea(xInicial, yInicial, xFinal, yFinal); // Crear el objeto Linea
        }
    } else {
        qDebug() << "Conexion NO exitosa";
    }
}

Widget::~Widget()
{
    delete linea; // Liberar la memoria del objeto Linea
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    if (linea) {
        // Dibujar la línea si el objeto Linea existe
        painter.drawLine(linea->getXInicial(), linea->getYInicial(), linea->getXFinal(), linea->getYFinal());
    }
}
