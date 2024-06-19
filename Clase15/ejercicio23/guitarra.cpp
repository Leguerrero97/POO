#include "guitarra.h"
#include <QDebug>

Guitarra::Guitarra(int cuerdas, const std::string& marca) : Instrumento(marca), cuerdas(cuerdas) {}

void Guitarra::sonar() const {
    qDebug() << "Guitarra suena...";
}

int Guitarra::getCuerdas() const {
    return cuerdas;
}

void Guitarra::setCuerdas(int num) {
    cuerdas = num;
}
