#ifndef MANAGER_H
#define MANAGER_H

#include "admindb.h"
#include "login.h"
#include "registrousuario.h"
#include "visualizacionusuarios.h"

class Manager {
public:
    Manager();

    void mostrarLogin();
    void mostrarRegistroUsuario();
    void mostrarVisualizacionUsuarios();

private:
    AdminDB *db;
    Login *loginWindow;
    RegistroUsuario *registroWindow;
    VisualizacionUsuarios *visualizacionWindow;
};

#endif // MANAGER_H
