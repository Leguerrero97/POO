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
};

#endif // FORMULARIO_H
