#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include "Formulario.h"

class Login : public QWidget {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);

public slots:
    void verificarClave();
};

#endif // LOGIN_H
