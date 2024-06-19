#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer> // <-- Agregar QTimer para el temporizador
#include "admindb.h"
#include "formulario.h"

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    void toggleTemperatureInfo();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void handleLogin();
    void slot_descargaFinalizada(QNetworkReply *reply);
    void onPasswordReturnPressed();
    void showBackground();
    void mostrarTemperatura(double temperatura);
    void toggleTemperatureDisplay();
    void habilitarLogin(); // <-- Declaración del slot para habilitar el login

private:
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QPushButton *toggleButton;
    QNetworkAccessManager *networkManager;
    QImage backgroundImage;
    QLabel *temperaturaLabel;
    bool temperaturaVisible;
    int intentosFallidos = 0;
    bool imagenActualizada = false;
    AdminDB* adminDB; // Declarar adminDB como puntero a AdminDB
};

#endif // LOGIN_H
