#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QVector>
#include <QStringList>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);
    ~AdminDB();

    bool conectar(QString archivoSqlite);
    QSqlDatabase getDB();
    bool isConnected();
    void mostrarTabla(QString tabla);
    QStringList validarUsuario(QString tabla, QString usuario, QString clave);
    QVector<QStringList> select(QString comando);

private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
