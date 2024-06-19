#ifndef VIENTO_H
#define VIENTO_H

#include "Instrumento.h"

class Viento : public Instrumento {
public:
    void afinar() const override {
        std::cout << "Afinando instrumento de viento" << std::endl;
    }

    QString metal_usado;
};

#endif // VIENTO_H
