#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    static AdminDB& instance();
    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    bool isConnected();
    void mostrarTabla(QString tabla);
    QSqlQuery select(QString consulta);

private:
    explicit AdminDB(QObject *parent = nullptr);
    ~AdminDB();
    QSqlDatabase db;
};

#endif // ADMINDB_H
