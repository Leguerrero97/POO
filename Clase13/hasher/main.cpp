#include <QApplication>
#include "hasher.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Hasher hasher;
    hasher.show();
    return a.exec();
}
