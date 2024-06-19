#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <QDebug>

class Electrico {
public:
    Electrico(int voltaje = 220);
    ~Electrico();

    // Declaración de los métodos get y set (sin definición)
    int getVoltaje() const;
    void setVoltaje(int v);

private:
    int voltaje;
};

#endif // ELECTRICO_H
