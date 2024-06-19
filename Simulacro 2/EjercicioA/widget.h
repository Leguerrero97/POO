// widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "adminDB.h"
#include "linea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Widget *ui;
    AdminDB adminDB;
    Linea *linea; // Cambio a un puntero de Linea
};
#endif // WIDGET_H
