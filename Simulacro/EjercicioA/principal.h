#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <QWidget>

#include <QWidget>
#include <QPixmap>

class ImageWidget : public QWidget {
    Q_OBJECT

public:
    explicit ImageWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap image;
};

#endif // PRINCIPAL_H
