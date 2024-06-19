#include "admindb.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

AdminDB::AdminDB(QObject *parent) : QObject(parent) {
    conectar("C:/Users/Lautaro/Documents/Qt/Clase 14/ejercicio21/14db.sqlite");
}

AdminDB::~AdminDB() {
    if (db.isOpen()) {
        db.close();
    }
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

QStringList AdminDB::validarUsuario(QString tabla, QString usuario, QString clave) {
    QStringList datosUsuario; // Cambiamos el nombre a datosUsuario

    if (!db.isOpen()) {
        qDebug() << "Error: La base de datos no está abierta.";
        return datosUsuario;
    }

    QSqlQuery query(db);
    query.prepare("SELECT clave_hash FROM " + tabla + " WHERE nombre = :usuario"); // Consulta corregida
    query.bindValue(":usuario", usuario.trimmed());

    if (query.exec() && query.next()) {
        QString claveHashAlmacenada = query.value(0).toString().trimmed();
        QByteArray claveHashIngresada = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5);
        QString claveMd5Ingresada = claveHashIngresada.toHex();

        if (claveMd5Ingresada == claveHashAlmacenada) {
            datosUsuario << usuario; // Solo devolvemos el nombre de usuario
            emit signal_usuarioValidado(usuario);
        } else {
            qDebug() << "Credenciales incorrectas para usuario:" << usuario;
            qDebug() << "Hash ingresado:" << claveMd5Ingresada;
            qDebug() << "Hash almacenado:" << claveHashAlmacenada;
        }
    } else {
        qDebug() << "Usuario no encontrado:" << usuario;
    }

    return datosUsuario; // Devolvemos los datos del usuario (vacío si no se encontró o la clave es incorrecta)
}

QVector<QStringList> AdminDB::select(const QString &comando) {
    QVector<QStringList> resultado;

    if (db.isOpen()) {
        QSqlQuery query(db);
        query.exec(comando);
        while (query.next()) {
            QSqlRecord registro = query.record();
            QStringList fila;
            for (int i = 0; i < registro.count(); ++i) {
                fila << registro.value(i).toString();
            }
            resultado << fila;
        }
    }

    return resultado;
}

bool AdminDB::registrar(QString usuario) {  // Cambiamos el parámetro a 'usuario'
    if (!db.isOpen()) {
        return false;
    }
    QSqlQuery query(db);
    // Actualizamos la consulta para usar la tabla "usuarios" y el campo "nombre"
    query.prepare("UPDATE usuarios SET intentos_fallidos = intentos_fallidos + 1 WHERE nombre = :usuario");
    query.bindValue(":usuario", usuario);

    if (!query.exec()) {
        qDebug() << "Error al registrar evento:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlDatabase AdminDB::getDB() const {
    return db;
}
