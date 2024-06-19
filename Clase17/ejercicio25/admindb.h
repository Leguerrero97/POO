#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QList>
#include <QString>

struct Usuario {
    int id;
    QString nombre;
    QString usuario;
    QString contrasena;
};

class AdminDB : public QObject {
    Q_OBJECT
private:
    static AdminDB *instancia;
    QSqlDatabase database;

    AdminDB();
    ~AdminDB();

public:
    static AdminDB *getInstancia();

    bool validarUsuario(const QString &usuario, const QString &contrasena);
    bool registrarUsuario(const QString &nombre, const QString &usuario, const QString &contrasena);
    QList<Usuario> obtenerUsuarios();
    bool editarUsuario(int id, const QString &nombre, const QString &usuario, const QString &contrasena);
    bool eliminarUsuario(int id);

private:
    void crearTablaUsuarios();
};

#endif // ADMINDB_H
