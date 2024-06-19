#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento {
public:
    Guitarra(int cuerdas = 6, const std::string& marca = "Yamaha");
    void sonar() const override;

    // Declaración de los métodos get y set (sin definición)
    int getCuerdas() const;
    void setCuerdas(int num);

private:
    int cuerdas;
};

#endif // GUITARRA_H
