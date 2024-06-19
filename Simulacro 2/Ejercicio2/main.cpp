#include <QApplication>
#include "admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Admin admin;

    return a.exec();
}
