#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include "login.h"
#include "ventana.h"
#include "admindb.h"

class Admin : public QObject
{
    Q_OBJECT
public:
    explicit Admin(QObject *parent = nullptr);
    ~Admin();

private slots:
    void onUsuarioValidado(QString usuario);

private:
    Login *loginWindow;
    Ventana *mainWindow;
    AdminDB *db;
};

#endif // ADMIN_H

