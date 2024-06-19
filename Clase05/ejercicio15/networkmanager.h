// networkmanager.h
#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QtNetwork>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *parent = nullptr);

    void crearUsuario(int legajo, const QString& nombre, const QString& apellido);

signals:
    void usuarioCreado();

private:
    QNetworkAccessManager *manager;
};

#endif // NETWORKMANAGER_H
