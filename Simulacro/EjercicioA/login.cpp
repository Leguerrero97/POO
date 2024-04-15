#include "login.h"
#include "principal.h"
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QKeyEvent>
#include <QApplication>

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent) {
    setFixedSize(250, 120);
    setWindowTitle("Login");

    layout = new QGridLayout(this);
    QLabel *userLabel = new QLabel("Usuario:", this);
    QLabel *passLabel = new QLabel("Clave:", this);
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password); // Configurar el modo de eco para ocultar con asteriscos
    passwordEdit->installEventFilter(this);
    layout->addWidget(userLabel, 0, 0);
    layout->addWidget(usernameEdit, 0, 1);
    layout->addWidget(passLabel, 1, 0);
    layout->addWidget(passwordEdit, 1, 1);

    // Conectar la señal returnPressed del QLineEdit de la clave a la función validateLogin
    connect(passwordEdit, &QLineEdit::returnPressed, this, &LoginWidget::validateLogin);
}

bool LoginWidget::eventFilter(QObject *obj, QEvent *event) {
    if (obj == passwordEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            validateLogin();
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);
}

void LoginWidget::validateLogin() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Comprobar si el nombre de usuario y la contraseña son válidos
    if (isValidLogin(username, password)) {
        // Inicio de sesión exitoso
        emit loginSuccess();
        // Ocultar LoginWidget
        hide();
        // Mostrar ImageWidget
        ImageWidget *imageWidget = new ImageWidget;
        imageWidget->show();
    } else {
        // Inicio de sesión fallido
        passwordEdit->clear(); // Limpiar solo el campo de la clave
        ++loginAttempts;
        if (loginAttempts >= 3) {
            QApplication::quit();
        }
    }
}

bool LoginWidget::isValidLogin(const QString& username, const QString& password) const {
    // Check if username is valid DNI and password is last 3 digits of DNI
    QString validUsername = "39969978"; // Replace with actual valid DNI
    QString validPassword = "978"; // Replace with actual valid last 3 digits
    return (username == validUsername && password == validPassword);
}
