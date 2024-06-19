#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <string>

class Instrumento {
public:
    Instrumento(const std::string& marca = "Yamaha");
    virtual ~Instrumento() {}
    virtual void sonar() const = 0;
    virtual void verMarca() const;

    // Declaración de función friend para comparar marcas
    friend bool compararMarcas(const Instrumento& i1, const Instrumento& i2);

protected:
    std::string marca;
};

#endif // INSTRUMENTO_H
