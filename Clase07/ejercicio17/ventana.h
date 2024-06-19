#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::Ventana *ui;
    QImage im;
    QNetworkAccessManager *manager;

private slots:
    void slot_descargaFinalizada(QNetworkReply *reply);
};

#endif // VENTANA_H
