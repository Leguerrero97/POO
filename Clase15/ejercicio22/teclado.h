#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico {
public:
    Teclado(int teclas = 61, const std::string& marca = "Yamaha", int voltaje = 220);
    void sonar() const override;
    int getTeclas() const;
    void setTeclas(int num);

private:
    int teclas;
};

#endif // TECLADO_H
