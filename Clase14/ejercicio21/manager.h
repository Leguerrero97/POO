#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <memory>
#include "login.h"
#include "ventana.h"

class Manager : public QObject {
    Q_OBJECT

public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager(); // Destructor para liberar los widgets

public slots:
    void mostrarLogin();
    void mostrarVentana(const QString &usuario);

private slots:
    void volverLogin();

private:
    std::unique_ptr<Login> loginWidget;
    std::unique_ptr<Ventana> ventanaWidget;
};

#endif // MANAGER_H
