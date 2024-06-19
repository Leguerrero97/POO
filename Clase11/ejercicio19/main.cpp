#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Pintura ventanaPintura;
    ventanaPintura.show();

    return app.exec();
}
