#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>

class AdminDB : public QObject {
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);

    bool validarUsuario(const QString &usuario, const QString &clave);
    QSqlDatabase getDB() const;
    bool registrar(QString evento);  // <-- Declaración de la función registrar

private:
    QSqlDatabase db;
    bool conectar(const QString &archivoSqlite);
};

#endif // ADMINDB_H
