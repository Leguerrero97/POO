#include "formulario.h"
#include <QMessageBox>
#include <QApplication>
#include <cstdlib>
#include <ctime>

Formulario::Formulario(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);

    QLabel *legajoLabel = new QLabel("Legajo:", this);
    legajoField = new QLineEdit(this);

    QLabel *nombreLabel = new QLabel("Nombre:", this);
    nombreField = new QLineEdit(this);

    QLabel *apellidoLabel = new QLabel("Apellido:", this);
    apellidoField = new QLineEdit(this);

    QLabel *captchaTextLabel = new QLabel("Captcha:", this);
    captchaLabel = new QLabel(generateCaptcha(), this);
    captchaField = new QLineEdit(this);

    altaButton = new QPushButton("Alta", this);

    layout->addWidget(legajoLabel, 0, 0);
    layout->addWidget(legajoField, 0, 1);
    layout->addWidget(nombreLabel, 1, 0);
    layout->addWidget(nombreField, 1, 1);
    layout->addWidget(apellidoLabel, 2, 0);
    layout->addWidget(apellidoField, 2, 1);
    layout->addWidget(captchaTextLabel, 3, 0);
    layout->addWidget(captchaLabel, 3, 1);
    layout->addWidget(captchaField, 4, 1);
    layout->addWidget(altaButton, 5, 0, 1, 2);

    setLayout(layout);

    connect(altaButton, &QPushButton::clicked, this, &Formulario::handleAlta);
    connect(legajoField, &QLineEdit::returnPressed, this, &Formulario::handleAlta);
    connect(nombreField, &QLineEdit::returnPressed, this, &Formulario::handleAlta);
    connect(apellidoField, &QLineEdit::returnPressed, this, &Formulario::handleAlta);
    connect(captchaField, &QLineEdit::returnPressed, this, &Formulario::handleAlta);
}

QString Formulario::generateCaptcha() {
    srand(time(0));
    int captchaValue = rand() % 9000 + 1000;
    return QString::number(captchaValue);
}

void Formulario::handleAlta() {
    QString legajo = legajoField->text();
    QString nombre = nombreField->text();
    QString apellido = apellidoField->text();
    QString captcha = captchaField->text();

    if (legajo.isEmpty() || nombre.isEmpty() || apellido.isEmpty()) {
        QMessageBox::warning(this, "Error", "Todos los campos son obligatorios");
        return;
    }

    if (captcha != captchaLabel->text()) {
        QMessageBox::warning(this, "Error", "Captcha incorrecto");
        captchaLabel->setText(generateCaptcha());
        captchaField->clear();
        return;
    }

    QMessageBox::information(this, "Éxito", "Datos válidos. Cerrando la aplicación.");
    QApplication::quit();
}

