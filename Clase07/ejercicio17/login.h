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

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void backgroundLoaded(); // Señal personalizada

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void handleLogin();
    void slot_descargaFinalizada(QNetworkReply *reply);
    void onPasswordReturnPressed();

private:
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QNetworkAccessManager *networkManager;
    QImage backgroundImage;
};

#endif // LOGIN_H
