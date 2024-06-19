#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QList>
#include <QPoint>
#include <QColor>

#include "ui_pintura.h"

// Declaración del struct Trazo
struct Trazo {
    QList<QPoint> puntos;
    QColor color;
    int grosor;
};

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::pintura *ui; // Puntero a la interfaz de usuario
    QColor colorPincel;
    int grosorPincel;
    QList<Trazo> trazos; // Lista de trazos (ahora usa el struct Trazo)
};

#endif // PINTURA_H
