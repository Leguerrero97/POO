#include "principal.h"
#include <QPainter>

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 250); // Tamaño del widget
    // Cargar la imagen desde el archivo
    image = QPixmap("C:/Users/Lautaro/Pictures/Depositphotos_415137580_XL.png");
}

void ImageWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Calcular las coordenadas para centrar la imagen en el widget
    int imageX = (width() - image.width()) / 2;
    int imageY = (height() - image.height()) / 2;
    painter.drawPixmap(imageX, imageY, image);

    // Obtener el rectángulo delimitador de la imagen
    QRect imageRect = image.rect();

    // Desplazar el rectángulo al centro del widget
    imageRect.moveCenter(rect().center());

    // Ajustar el tamaño del rectángulo para que sea un poco más grande que la imagen
    int padding = 2;
    imageRect.adjust(-padding, -padding, padding, padding);
    painter.setPen(QPen(Qt::black, 2));
    painter.drawRect(imageRect);
}
