#include "bateria.h"
#include <QDebug>

Bateria::Bateria(int tambores, const std::string& marca) : Instrumento(marca), tambores(tambores) {}

void Bateria::sonar() const {
    qDebug() << "Batería suena...";
}

int Bateria::getTambores() const {
    return tambores;
}

void Bateria::setTambores(int num) {
    tambores = num;
}
