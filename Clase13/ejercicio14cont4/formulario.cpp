#include "formulario.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);

    QLabel *legajoLabel = new QLabel("Legajo:", this);
    legajoField = new QLineEdit(this);

    QLabel *nombreLabel = new QLabel("Nombre:", this);
    nombreField = new QLineEdit(this);

    QLabel *apellidoLabel = new QLabel("Apellido:", this);
    apellidoField = new QLineEdit(this);

    layout->addWidget(legajoLabel, 0, 0);
    layout->addWidget(legajoField, 0, 1);
    layout->addWidget(nombreLabel, 1, 0);
    layout->addWidget(nombreField, 1, 1);
    layout->addWidget(apellidoLabel, 2, 0);
    layout->addWidget(apellidoField, 2, 1);

    setLayout(layout);
}
