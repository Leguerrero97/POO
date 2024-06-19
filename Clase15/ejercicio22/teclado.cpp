#include "teclado.h"
#include <QDebug>

Teclado::Teclado(int teclas, const std::string& marca, int voltaje)
    : Instrumento(marca), Electrico(voltaje), teclas(teclas) {}

void Teclado::sonar() const {
    qDebug() << "Teclado suena...";
}

int Teclado::getTeclas() const {
    return teclas;
}

void Teclado::setTeclas(int num) {
    teclas = num;
}
