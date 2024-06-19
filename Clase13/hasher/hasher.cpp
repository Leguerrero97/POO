#include "hasher.h"
#include <QVBoxLayout>

Hasher::Hasher(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    inputLineEdit = new QLineEdit(this);
    layout->addWidget(inputLineEdit);

    hashButton = new QPushButton("Calcular Hash MD5", this);
    connect(hashButton, &QPushButton::clicked, this, &Hasher::onHashButtonClicked);
    layout->addWidget(hashButton);

    outputLineEdit = new QLineEdit(this);  // Cambiamos QLabel por QLineEdit
    outputLineEdit->setReadOnly(true);    // Hacemos el QLineEdit de solo lectura
    layout->addWidget(outputLineEdit);

    setLayout(layout);
}

void Hasher::onHashButtonClicked() {
    QString clave = inputLineEdit->text();
    QByteArray claveHash = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5);
    QString claveMd5 = claveHash.toHex();

    outputLineEdit->setText(claveMd5);

    // Aquí puedes agregar el código para almacenar el hash en tu base de datos
    // utilizando el método AdminDB::agregarUsuarioConHash() de tu otro programa
}
