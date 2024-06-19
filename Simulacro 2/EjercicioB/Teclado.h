#ifndef TECLADO_H
#define TECLADO_H

#include "Instrumento.h"

class Teclado : public Instrumento {
public:
    void afinar() const override {
        std::cout << "Afinando teclado" << std::endl;
    }

    int cantidad_de_teclas;
};

#endif // TECLADO_H
