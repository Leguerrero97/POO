#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);

private slots:
    void handleAlta();

private:
    QLineEdit *legajoField;
    QLineEdit *nombreField;
    QLineEdit *apellidoField;
    QLineEdit *captchaField;
    QLabel *captchaLabel;
    QPushButton *altaButton;
    QString generateCaptcha();
};

#endif // FORMULARIO_H
