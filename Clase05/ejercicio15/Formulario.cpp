#include "Formulario.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent) {
    QLabel *labelLegajo = new QLabel("Legajo:");
    QLabel *labelNombre = new QLabel("Nombre:");
    QLabel *labelApellido = new QLabel("Apellido:");

    lineEditLegajo = new QLineEdit;
    lineEditNombre = new QLineEdit;
    lineEditApellido = new QLineEdit;

    buttonGuardar = new QPushButton("Guardar");
    captchaWidget = new CaptchaWidget;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(labelLegajo, 0, 0);
    layout->addWidget(lineEditLegajo, 0, 1);
    layout->addWidget(labelNombre, 1, 0);
    layout->addWidget(lineEditNombre, 1, 1);
    layout->addWidget(labelApellido, 2, 0);
    layout->addWidget(lineEditApellido, 2, 1);
    layout->addWidget(captchaWidget, 3, 0, 1, 2);
    layout->addWidget(buttonGuardar, 4, 0, 1, 2);

    setLayout(layout);

    connect(buttonGuardar, SIGNAL(clicked()), this, SLOT(guardarDatos()));
    connect(captchaWidget, SIGNAL(captchaChecked(bool)), this, SLOT(verificarCaptcha(bool)));
}

void Formulario::guardarDatos() {
    if (validarCampos()) {
        // Verificar si el captcha es correcto antes de guardar los datos
        captchaWidget->checkCaptcha();
    }
}

void Formulario::verificarCaptcha(bool captchaCorrecto) {
    if (captchaCorrecto) {
        QMessageBox::information(this, "Información", "Datos guardados correctamente.");
        // Limpia los campos después de guardar los datos
        lineEditLegajo->clear();
        lineEditNombre->clear();
        lineEditApellido->clear();
    } else {
        QMessageBox::critical(this, "Error", "Captcha incorrecto");
    }
}

bool Formulario::validarCampos() {
    if (lineEditLegajo->text().isEmpty() || lineEditNombre->text().isEmpty() || lineEditApellido->text().isEmpty()) {
        QMessageBox::critical(this, "Error", "Por favor, complete todos los campos.");
        return false;
    }
    return true;
}
