#include "admindb.h"
#include <QDebug>
#include <QSqlQuery>
#include<QSqlError>

AdminDB::AdminDB(QObject *parent) : QObject(parent) {
    conectar("C:/Users/Lautaro/Documents/Qt/Clase12/ejercicio14cont3/14db.sqlite");
}

bool AdminDB::conectar(const QString &archivoSqlite) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(archivoSqlite);
    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos:" << db.lastError().text();
        return false;
    }
    return true;
}

bool AdminDB::validarUsuario(const QString &usuario, const QString &clave) {
    if (!db.isOpen()) {
        qDebug() << "Error: La base de datos no está abierta.";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM usuarios WHERE usuario = :usuario AND clave = :clave");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", clave);

    if (query.exec() && query.next()) {
        return true;
    } else {
        qDebug() << "Error en la consulta:" << query.lastError().text();
        return false;
    }
}

bool AdminDB::registrar(QString evento) {
    if (!db.isOpen()) {
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO registros (evento) VALUES (:evento)");
    query.bindValue(":evento", evento);
    if (!query.exec()) {
        qDebug() << "Error al registrar evento:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlDatabase AdminDB::getDB() const {
    return db;
}
