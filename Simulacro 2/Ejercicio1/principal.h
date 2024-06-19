#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QVector>
#include "admindb.h"
#include "rectangulo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QWidget
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::Principal *ui;
    QVector<Rectangulo> rectangulos;

    void cargarRectangulos();
};

#endif // PRINCIPAL_H


