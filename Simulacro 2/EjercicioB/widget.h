#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include "Instrumento.h"
#include "guitarra.h"
#include "viento.h"
#include "Teclado.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void agregarInstrumento();
    void verStock();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Widget *ui;
    QVector<Instrumento*> instrumentos;
};

#endif // WIDGET_H

