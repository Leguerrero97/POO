/login.h
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QDebug>
#include <QImage>

class Login : public QWidget {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);

public slots:
    void verificarClave();
    void toggleTemperatura();
    void slot_descargaFinalizada(QNetworkReply *reply);

private:
    QLineEdit *lineEditUsuario;
    QLineEdit *lineEditClave;
    QPushButton *buttonMostrarTemperatura;
    QLabel *labelTemperatura;
    QNetworkAccessManager *manager;

    void obtenerTemperatura();
};

#endif // LOGIN_H
