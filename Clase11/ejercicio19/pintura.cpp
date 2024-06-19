#include "pintura.h"
#include "ui_pintura.h"

Pintura::Pintura(QWidget *parent) : QWidget(parent), ui(new Ui::pintura) {
    ui->setupUi(this);
    colorPincel = Qt::red;
    grosorPincel = 5;
}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    for (const Trazo &trazo : trazos) {
        painter.setPen(QPen(trazo.color, trazo.grosor, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        for (int i = 1; i < trazo.puntos.size(); ++i) {
            painter.drawLine(trazo.puntos[i - 1], trazo.puntos[i]);
        }
    }
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    trazos.append(Trazo{QList<QPoint>(), colorPincel, grosorPincel});
    trazos.last().puntos.append(event->pos());
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        trazos.last().puntos.append(event->pos());
        update();
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) {
        grosorPincel += 2;
    } else {
        grosorPincel -= 2;
        if (grosorPincel < 1) grosorPincel = 1;
    }
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_R) {
        colorPincel = Qt::red;
    } else if (event->key() == Qt::Key_G) {
        colorPincel = Qt::green;
    } else if (event->key() == Qt::Key_B) {
        colorPincel = Qt::blue;
    } else if (event->key() == Qt::Key_Escape) {
        trazos.clear();
        update();
    }
}
