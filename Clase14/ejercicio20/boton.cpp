#include "boton.h"
#include <QPainter>
#include <QMouseEvent>

Boton::Boton(QWidget *parent) : QWidget(parent), m_color(Qt::red), m_text("") {}

void Boton::colorear(Color color) {
    switch (color) {
        case Rojo:
            m_color = Qt::red;
            break;
        case Azul:
            m_color = Qt::blue;
            break;
        case Verde:
            m_color = Qt::green;
            break;
        case Magenta:
            m_color = Qt::magenta;
            break;
    }
    update();
}

void Boton::setText(const QString &text) {
    m_text = text;
    update();
}

QString Boton::text() const {
    return m_text;
}

void Boton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.fillRect(rect(), m_color);

    // Dibujar el texto centrado
    QFontMetrics metrics(painter.font());
    int textWidth = metrics.horizontalAdvance(m_text);
    int textHeight = metrics.height();

    int x = rect().center().x() - textWidth / 2;
    int y = rect().center().y() + textHeight / 4; // Ajuste vertical para centrar mejor el texto

    painter.drawText(x, y, m_text);
}

void Boton::mousePressEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    if (m_color == Qt::red) {
        colorear(Magenta);
    } else if (m_color == Qt::magenta) {
        colorear(Azul);
    } else if (m_color == Qt::blue) {
        colorear(Verde);
    } else {
        colorear(Rojo);
    }
    emit signal_clic();
}
