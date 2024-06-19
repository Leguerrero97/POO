#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QVector>
#include <QStringList>
#include <QCryptographicHash>

class AdminDB : public QObject {
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);
    ~AdminDB();

    bool conectar(const QString &archivoSqlite);
    QStringList validarUsuario(QString tabla, QString usuario, QString clave);
    QSqlDatabase getDB() const;

    QVector<QStringList> select(const QString &comando);

    bool registrar(QString evento);

signals:
    void signal_usuarioValidado(QString usuario);

private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
