#include "Login.h"

Login::Login(QWidget *parent) : QWidget(parent) {
    QLabel *labelClave = new QLabel("Clave:");
    QLineEdit *lineEditClave = new QLineEdit;
    lineEditClave->setEchoMode(QLineEdit::Password);
    QPushButton *buttonIngresar = new QPushButton("Ingresar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(labelClave, 0, 0);
    layout->addWidget(lineEditClave, 0, 1);
    layout->addWidget(buttonIngresar, 1, 0, 1, 2);

    setLayout(layout);

    connect(lineEditClave, SIGNAL(returnPressed()), this, SLOT(verificarClave()));
    connect(buttonIngresar, SIGNAL(clicked()), this, SLOT(verificarClave()));
}

void Login::verificarClave() {
    QString clave = "admin:1111";
    QLineEdit *lineEditClave = qobject_cast<QLineEdit*>(sender());
    if (lineEditClave) {
        if (lineEditClave->text() == clave) {
            // Si la clave es correcta, cerramos el Login y mostramos el Formulario
            Formulario *formulario = new Formulario;
            formulario->show();
            close();
        } else {
            // Si la clave es incorrecta, borramos el texto del QLineEdit de la clave
            lineEditClave->clear();
            qApp->quit();
        }
    }
}
