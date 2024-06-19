#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QPushButton>

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

signals:
    void signal_volverLogin(); // Señal para volver al login

private slots:
    void volverLogin(); // Slot para volver al login

private:
    QPushButton *volverButton;
};

#endif // VENTANA_H
