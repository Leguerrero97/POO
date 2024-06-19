#include "imagewidget.h"
#include <QPainter>

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent) {}

void ImageWidget::loadImage(const QString &filePath) {
    if (pixmap.load(filePath)) { // Intenta cargar la imagen
        update(); // Si se carga correctamente, actualiza el widget para volver a dibujar
    } else {
        // Manejo de errores si la imagen no se pudo cargar
        pixmap = QPixmap(); // Borra la imagen anterior si había una
        update(); // Actualiza el widget para borrar la imagen anterior
    }
}

void ImageWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Calculamos las dimensiones para escalar la imagen proporcionalmente
    int imageWidth = pixmap.width();
    int imageHeight = pixmap.height();
    int widgetWidth = width();
    int widgetHeight = height();

    int scaledWidth, scaledHeight;
    if (imageWidth > widgetWidth || imageHeight > widgetHeight) {
        // La imagen es más grande que el widget, escalamos proporcionalmente
        double widthRatio = static_cast<double>(widgetWidth) / imageWidth;
        double heightRatio = static_cast<double>(widgetHeight) / imageHeight;
        double scaleFactor = std::min(widthRatio, heightRatio);
        scaledWidth = static_cast<int>(imageWidth * scaleFactor);
        scaledHeight = static_cast<int>(imageHeight * scaleFactor);
    } else {
        // La imagen es más pequeña que el widget, la mostramos en su tamaño original
        scaledWidth = imageWidth;
        scaledHeight = imageHeight;
    }

    // Calculamos las coordenadas para centrar la imagen
    int x = (widgetWidth - scaledWidth) / 2;
    int y = (widgetHeight - scaledHeight) / 2;

    // Dibujamos la imagen escalada y centrada
    painter.drawPixmap(x, y, scaledWidth, scaledHeight, pixmap);
}
