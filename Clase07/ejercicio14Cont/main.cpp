#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Login loginWindow;
    loginWindow.show();
    return a.exec();
}