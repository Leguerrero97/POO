#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <string>

class Instrumento {
public:
    Instrumento(const std::string& marca = "Yamaha");
    virtual ~Instrumento() {}
    virtual void sonar() const = 0;
    virtual void verMarca() const;

protected:
    std::string marca;
};

#endif // INSTRUMENTO_H
