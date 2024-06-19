#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QPixmap>

class ImageWidget : public QWidget {
    Q_OBJECT

public:
    explicit ImageWidget(QWidget *parent = nullptr);

public slots:
    void loadImage(const QString &filePath);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap pixmap;
};

#endif // IMAGEWIDGET_H
