#ifndef CAPTCHAWIDGET_H
#define CAPTCHAWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QRandomGenerator>

class CaptchaWidget : public QWidget {
    Q_OBJECT
public:
    CaptchaWidget(QWidget *parent = nullptr);

signals:
    void captchaChecked(bool);

public slots:
    void checkCaptcha();

private:
    QLabel *captchaLabel;
    QLineEdit *captchaLineEdit;
};

#endif // CAPTCHAWIDGET_H
