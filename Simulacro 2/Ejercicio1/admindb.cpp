#include "admindb.h"
#include <QDebug>

AdminDB::AdminDB(QObject *parent) : QObject(parent) {
    qDebug() << "Drivers disponibles:" << QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QSQLITE");
}

AdminDB::~AdminDB() {
    if (db.isOpen())
        db.close();
}

AdminDB& AdminDB::instance() {
    static AdminDB instance;
    return instance;
}

bool AdminDB::conectar(QString archivoSqlite) {
    db.setDatabaseName(archivoSqlite);
    return db.open();
}

QSqlDatabase AdminDB::getDB() {
    return db;
}

bool AdminDB::isConnected() {
    return db.isOpen();
}

void AdminDB::mostrarTabla(QString tabla) {
    if (this->isConnected()) {
        QSqlQuery query = db.exec("SELECT * FROM " + tabla);
        if (query.size() == 0 || query.size() == -1)
            qDebug() << "La consulta no trajo registros";
        while (query.next()) {
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

QSqlQuery AdminDB::select(QString consulta) {
    QSqlQuery query(db);
    query.exec(consulta);
    return query;
}
