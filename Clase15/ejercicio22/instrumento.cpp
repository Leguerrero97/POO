#include "instrumento.h"
#include <QDebug>
#include <QString>

Instrumento::Instrumento(const std::string& marca) : marca(marca) {}

void Instrumento::verMarca() const {
    qDebug() << "Marca:" << QString::fromStdString(marca);
}
