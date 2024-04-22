#include <QApplication>
#include "Login.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    // Creación de la ventana de inicio de sesión y muestra
    Login login;
    login.show();

    return app.exec();
}
