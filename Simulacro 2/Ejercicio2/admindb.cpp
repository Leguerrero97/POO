#include "admindb.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QCryptographicHash>

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    qDebug() << "Drivers disponibles:" << QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QSQLITE");
}

AdminDB::~AdminDB()
{
    if (db.isOpen())
        db.close();
}

bool AdminDB::conectar(QString archivoSqlite)
{
    db.setDatabaseName(archivoSqlite);
    return db.open();
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}

bool AdminDB::isConnected()
{
    return db.isOpen();
}

void AdminDB::mostrarTabla(QString tabla)
{
    if (this->isConnected()) {
        QSqlQuery query = db.exec("SELECT * FROM " + tabla);

        if (query.size() == 0 || query.size() == -1)
            qDebug() << "La consulta no trajo registros";

        while(query.next()) {
            QSqlRecord registro = query.record();
            int campos = registro.count();
            QString informacion;
            for (int i = 0; i < campos; i++) {
                informacion += registro.fieldName(i) + ":";
                informacion += registro.value(i).toString() + " - ";
            }
            qDebug() << informacion;
        }
    } else {
        qDebug() << "No se encuentra conectado a la base";
    }
}

QStringList AdminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
    QStringList datosPersonales;
    if (!db.isOpen())
        return datosPersonales;

    QSqlQuery query(db);
    QString claveMd5 = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
    query.exec("SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" + usuario + "' AND clave = '" + claveMd5 + "'");

    while (query.next()) {
        QSqlRecord registro = query.record();
        datosPersonales << query.value(registro.indexOf("nombre")).toString();
        datosPersonales << query.value(registro.indexOf("apellido")).toString();
    }

    return datosPersonales;
}

QVector<QStringList> AdminDB::select(QString comando)
{
    QVector<QStringList> resultado;
    if (!db.isOpen())
        return resultado;

    QSqlQuery query(db);
    query.exec(comando);

    while (query.next()) {
        QSqlRecord registro = query.record();
        QStringList fila;
        for (int i = 0; i < registro.count(); i++) {
            fila << registro.value(i).toString();
        }
        resultado.append(fila);
    }

    return resultado;
}
