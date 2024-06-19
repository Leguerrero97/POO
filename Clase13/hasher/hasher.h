#ifndef HASHER_H
#define HASHER_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QCryptographicHash>

class Hasher : public QWidget {
    Q_OBJECT

public:
    explicit Hasher(QWidget *parent = nullptr);

private slots:
    void onHashButtonClicked();

private:
    QLineEdit *inputLineEdit;
    QPushButton *hashButton;
    QLineEdit *outputLineEdit;
};

#endif // HASHER_H
