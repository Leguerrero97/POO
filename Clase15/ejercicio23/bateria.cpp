#include "bateria.h"
#include <QDebug>

Bateria::Bateria(int tambores, const std::string& marca) : Instrumento(marca), tambores(tambores) {}

void Bateria::sonar() const {
    qDebug() << "Batería suena...";
}

// Definición de los métodos get y set
int Bateria::getTambores() const {
    return tambores;
}

void Bateria::setTambores(int num) {
    tambores = num;
}
