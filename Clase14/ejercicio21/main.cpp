#include <QApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Manager manager;
    manager.mostrarLogin(); // Mostrar el login al iniciar
    return a.exec();
}
