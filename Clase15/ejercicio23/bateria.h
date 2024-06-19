#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento {
public:
    Bateria(int tambores = 5, const std::string& marca = "Yamaha");
    void sonar() const override;

    // Declaración de los métodos get y set (sin definición)
    int getTambores() const;
    void setTambores(int num);

private:
    int tambores;
};

#endif // BATERIA_H
