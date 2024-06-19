#include "login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) : QWidget(parent) {
    QGridLayout *layout = new QGridLayout(this);

    QLabel *usernameLabel = new QLabel("Usuario:", this);
    usernameField = new QLineEdit(this);

    QLabel *passwordLabel = new QLabel("Clave:", this);
    passwordField = new QLineEdit(this);
    passwordField->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);

    layout->addWidget(usernameLabel, 0, 0);
    layout->addWidget(usernameField, 0, 1);
    layout->addWidget(passwordLabel, 1, 0);
    layout->addWidget(passwordField, 1, 1);
    layout->addWidget(loginButton, 2, 0, 1, 2);

    setLayout(layout);

    connect(loginButton, &QPushButton::clicked, this, &Login::handleLogin);
    connect(passwordField, &QLineEdit::returnPressed, this, &Login::handleLogin);
}

void Login::handleLogin() {
    QString username = usernameField->text();
    QString password = passwordField->text();

    if (username == "admin" && password == "1111") {
        this->close();
        Formulario *form = new Formulario();
        form->show();
    } else {
        QMessageBox::warning(this, "Error", "Clave incorrecta");
        passwordField->clear();
    }
}
