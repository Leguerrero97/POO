#include "ventana.h"
#include "boton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;
    w.show();
    return a.exec();
}
