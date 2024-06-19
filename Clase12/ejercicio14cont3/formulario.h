#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);

private:
    QLineEdit *legajoField;
    QLineEdit *nombreField;
    QLineEdit *apellidoField;
};

#endif // FORMULARIO_H
