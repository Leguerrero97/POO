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

protected:
    void paintEvent(QPaintEvent *event) override;
    void setBackgroundImage(const QUrl &url);

private slots:
    void handleLogin();
    void fetchTemperature();
    void displayTemperature(QNetworkReply *reply);
    void toggleTemperatureDisplay();
    void backgroundImageDownloaded(QNetworkReply *reply);

private:
    QLineEdit *usernameField;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QLabel *temperatureLabel;
    QPushButton *toggleTempButton;
    QNetworkAccessManager *networkManager;
    QImage backgroundImage; // Se usa QImage en lugar de QPixmap
    bool isTempVisible;
};

#endif // LOGIN_H
