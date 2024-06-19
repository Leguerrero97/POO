#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Manager;

class RegistroUsuario : public QWidget {
    Q_OBJECT
public:
    explicit RegistroUsuario(Manager *parent = nullptr);

signals:
    void registroExitoso();

private slots:
    void onRegistrarClicked();

private:
    QLineEdit *nombreLineEdit;
    QLineEdit *usuarioLineEdit;
    QLineEdit *contrasenaLineEdit;
    QPushButton *registrarButton;
    Manager *manager;
};

#endif // REGISTROUSUARIO_H
