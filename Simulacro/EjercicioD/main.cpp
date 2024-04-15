#include <QApplication>
#include "galeria.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    PhotoGallery gallery;
    gallery.show();
    return app.exec();
}
