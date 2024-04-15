#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

class QLineEdit;
class QGridLayout;

class LoginWidget : public QWidget {
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);

signals:
    void loginSuccess();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void validateLogin();
    bool isValidLogin(const QString& username, const QString& password) const;

private:
    QGridLayout *layout;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    int loginAttempts = 0;
};

#endif // LOGIN_H
