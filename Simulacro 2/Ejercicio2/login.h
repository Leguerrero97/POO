#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void signal_usuarioValidado(QString usuario);

private slots:
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
