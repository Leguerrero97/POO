#include "admindb.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

AdminDB* AdminDB::instancia = nullptr;

AdminDB::AdminDB() {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("usuarios.db");

    if (!database.open()) {
        qDebug() << "Error al abrir la base de datos:" << database.lastError().text();
    } else {
        crearTablaUsuarios();
    }
}

AdminDB::~AdminDB() {
    if (database.isOpen()) {
        database.close();
    }
}

AdminDB* AdminDB::getInstancia() {
    if (instancia == nullptr) {
        instancia = new AdminDB();
    }
    return instancia;
}

bool AdminDB::validarUsuario(const QString &usuario, const QString &contrasena) {
    QSqlQuery query(database);
    query.prepare("SELECT * FROM usuarios WHERE usuario = :usuario AND contrasena = :contrasena");
    query.bindValue(":usuario", usuario);
    query.bindValue(":contrasena", contrasena);

    if (!query.exec()) {
        qDebug() << "Error en la consulta:" << query.lastError().text();
        return false;
    }

    return query.next(); // Devuelve true si se encontró el usuario
}

bool AdminDB::registrarUsuario(const QString &nombre, const QString &usuario, const QString &contrasena) {
    QSqlQuery query(database);
    query.prepare("INSERT INTO usuarios (nombre, usuario, contrasena) VALUES (:nombre, :usuario, :contrasena)");
    query.bindValue(":nombre", nombre);
    query.bindValue(":usuario", usuario);
    query.bindValue(":contrasena", contrasena);

    if (!query.exec()) {
        qDebug() << "Error al registrar usuario:" << query.lastError().text();
        return false;
    }

    return true;
}

QList<Usuario> AdminDB::obtenerUsuarios() {
    QList<Usuario> usuarios;
    QSqlQuery query(database);
    query.exec("SELECT * FROM usuarios");

    while (query.next()) {
        Usuario usuario;
        usuario.id = query.value("id").toInt();
        usuario.nombre = query.value("nombre").toString();
        usuario.usuario = query.value("usuario").toString();
        usuario.contrasena = query.value("contrasena").toString();
        usuarios.append(usuario);
    }

    return usuarios;
}

void AdminDB::crearTablaUsuarios() {
    QSqlQuery query(database);
    query.exec("CREATE TABLE IF NOT EXISTS usuarios (id INTEGER PRIMARY KEY AUTOINCREMENT, nombre TEXT, usuario TEXT, contrasena TEXT)");
}
