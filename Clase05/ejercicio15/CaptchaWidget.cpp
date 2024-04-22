#include "CaptchaWidget.h"

CaptchaWidget::CaptchaWidget(QWidget *parent) : QWidget(parent) {
    captchaLabel = new QLabel(QString::number(QRandomGenerator::global()->bounded(1, 10001)));
    captchaLineEdit = new QLineEdit;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel("<b>Captcha</b>"), 0, 0, 1, 2);
    layout->addWidget(new QLabel("Número a ingresar:"), 1, 0);
    layout->addWidget(captchaLabel, 1, 1);
    layout->addWidget(new QLabel("Ingrese el texto:"), 2, 0);
    layout->addWidget(captchaLineEdit, 2, 1);

    setLayout(layout);
}

void CaptchaWidget::checkCaptcha() {
    QString input = captchaLineEdit->text();
    if (input == captchaLabel->text()) {
        emit captchaChecked(true);
    } else {
        QMessageBox::critical(this, "Error", "Captcha incorrecto");
        captchaLabel->setText(QString::number(QRandomGenerator::global()->bounded(1, 10001)));
        captchaLineEdit->clear();
    }
}
