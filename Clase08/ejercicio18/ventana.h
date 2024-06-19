#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void onUrlEntered();
    void onHtmlDownloaded(QNetworkReply* reply);

private:
    QLineEdit *urlLineEdit;
    QPushButton *fetchButton;
    QTextEdit *htmlTextEdit;
    QNetworkAccessManager *networkManager;
};

#endif // VENTANA_H
