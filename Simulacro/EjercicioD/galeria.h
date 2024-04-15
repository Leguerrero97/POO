#ifndef GALERIA_H
#define GALERIA_H

#include <QWidget>
#include <QVector>
#include <QString>

class PhotoGallery : public QWidget {
    Q_OBJECT

public:
    PhotoGallery(QWidget *parent = nullptr);

private slots:
    void previousPhoto();
    void nextPhoto();

private:
    QVector<QString> photoURLs;
    int currentIndex;

    void loadPhotoURLsFromFile(const QString &fileName);
    void showCurrentPhoto();
};

#endif // GALERIA_H
