#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "formulario.h"

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

private slots:
    void handleLogin();

private:
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
};

#endif // LOGIN_H
