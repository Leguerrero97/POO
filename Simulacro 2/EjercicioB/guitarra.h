#ifndef GUITARRA_H
#define GUITARRA_H

#include "Instrumento.h"
#include <iostream>

class Guitarra : public Instrumento {
public:
    void afinar() const override {
        std::cout << "Afinando guitarra" << std::endl;
    }

    int cantidad_de_cuerdas;
};

#endif // GUITARRA_H
