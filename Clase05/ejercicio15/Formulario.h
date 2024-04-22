#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include "CaptchaWidget.h"

class Formulario : public QWidget {
    Q_OBJECT
public:
    Formulario(QWidget *parent = nullptr);

private slots:
    void guardarDatos();

    // Slot para verificar el captcha
    void verificarCaptcha(bool captchaCorrecto);

private:
    CaptchaWidget *captchaWidget;
    QPushButton *buttonGuardar;
    QLineEdit *lineEditLegajo;
    QLineEdit *lineEditNombre;
    QLineEdit *lineEditApellido;

    bool validarCampos();
};

#endif // FORMULARIO_H
