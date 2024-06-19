#include "instrumento.h"
#include <QDebug>
#include <QString>

Instrumento::Instrumento(const std::string& marca) : marca(marca) {}

void Instrumento::verMarca() const {
    qDebug() << "Marca:" << QString::fromStdString(marca);
}

// Definición de la función friend para comparar marcas
bool compararMarcas(const Instrumento& i1, const Instrumento& i2) {
    return i1.marca == i2.marca;
}
