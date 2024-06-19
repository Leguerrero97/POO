#include "ventana.h"
#include <QPushButton>
#include <QVBoxLayout> // Para organizar los elementos verticalmente

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    // Crear el botón "Volver"
    volverButton = new QPushButton("Volver", this);

    // Conectar la señal clicked del botón al slot volverLogin
    connect(volverButton, &QPushButton::clicked, this, &Ventana::volverLogin);

    // Crear un layout vertical para organizar los elementos
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Agregar el botón al layout
    layout->addWidget(volverButton);

    // Establecer el layout de la ventana
    setLayout(layout);
}

void Ventana::volverLogin() {
    // Cierra la ventana actual (Ventana)
    this->close();

    // Emite la señal para que el Manager muestre el Login
    emit signal_volverLogin();
}

