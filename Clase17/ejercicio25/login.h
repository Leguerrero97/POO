#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Manager;

class Login : public QWidget {
    Q_OBJECT
public:
    explicit Login(Manager *parent = nullptr);

signals:
    void loginExitoso();
    void abrirRegistro();

private slots:
    void onLoginClicked();

private:
    QLineEdit *usuarioLineEdit;
    QLineEdit *contrasenaLineEdit;
    QPushButton *loginButton;
    QPushButton *registrarButton;
    Manager *manager;
};

#endif // LOGIN_H
