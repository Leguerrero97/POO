#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnLogin_clicked()
{
    QString usuario = ui->lineEditUsuario->text();
    QString clave = ui->lineEditClave->text();

    emit signal_usuarioValidado(usuario); // Envía la señal al Admin para la validación del usuario
}
