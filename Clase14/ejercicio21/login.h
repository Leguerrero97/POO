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
#include <QTimer>
#include <QSettings>
#include <QStandardPaths>
#include "admindb.h"

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void signal_usuarioValidado(QString usuario); // Señal para login exitoso

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void handleLogin();
    void slot_descargaFinalizada(QNetworkReply *reply);
    void onPasswordReturnPressed();
    void mostrarTemperatura(double temperatura);
    void toggleTemperatureDisplay();
    void habilitarLogin();
    void on_usuarioValidado(QString usuario); // <-- Slot para recibir la señal (coincidente con adminDB.h)

private:
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QPushButton *toggleButton;
    QNetworkAccessManager *networkManager;
    QImage backgroundImage;
    QLabel *temperaturaLabel;
    void toggleTemperatureInfo();
    bool temperaturaVisible = false; // Inicializamos temperaturaVisible
    int intentosFallidos = 0;
    bool imagenActualizada = false;
    AdminDB* adminDB;
};

#endif // LOGIN_H
