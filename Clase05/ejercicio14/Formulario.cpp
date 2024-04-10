#include "Formulario.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent) {
    QLabel *labelLegajo = new QLabel("Legajo:");
    QLabel *labelNombre = new QLabel("Nombre:");
    QLabel *labelApellido = new QLabel("Apellido:");

    QLineEdit *lineEditLegajo = new QLineEdit;
    QLineEdit *lineEditNombre = new QLineEdit;
    QLineEdit *lineEditApellido = new QLineEdit;

    QPushButton *buttonGuardar = new QPushButton("Guardar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(labelLegajo, 0, 0);
    layout->addWidget(lineEditLegajo, 0, 1);
    layout->addWidget(labelNombre, 1, 0);
    layout->addWidget(lineEditNombre, 1, 1);
    layout->addWidget(labelApellido, 2, 0);
    layout->addWidget(lineEditApellido, 2, 1);
    layout->addWidget(buttonGuardar, 3, 0, 1, 2);

    setLayout(layout);

    connect(buttonGuardar, SIGNAL(clicked()), this, SLOT(guardarDatos()));
}

void Formulario::guardarDatos() {
    QMessageBox::information(this, "Información", "Datos guardados correctamente.");
}
