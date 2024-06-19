#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <iostream>

class Instrumento {
public:
    virtual ~Instrumento() {}
    virtual void afinar() const = 0;

    QString marca;
    double precio;
};

#endif // INSTRUMENTO_H
