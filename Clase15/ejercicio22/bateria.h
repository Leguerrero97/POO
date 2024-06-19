#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento {
public:
    Bateria(int tambores = 5, const std::string& marca = "Yamaha");
    void sonar() const override;
    int getTambores() const;
    void setTambores(int num);

private:
    int tambores;
};

#endif // BATERIA_H
