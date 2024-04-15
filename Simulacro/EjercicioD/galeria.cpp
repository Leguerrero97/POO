#include "galeria.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QDebug>

PhotoGallery::PhotoGallery(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *imageLabel = new QLabel(this);
    layout->addWidget(imageLabel);

    QPushButton *prevButton = new QPushButton("<<", this);
    QPushButton *nextButton = new QPushButton(">>", this);
    layout->addWidget(prevButton);
    layout->addWidget(nextButton);

    connect(prevButton, &QPushButton::clicked, this, &PhotoGallery::previousPhoto);
    connect(nextButton, &QPushButton::clicked, this, &PhotoGallery::nextPhoto);

    loadPhotoURLsFromFile("C:/Users/Lautaro/Documents/Qt/Simulacro/photo_urls.txt.txt");

    currentIndex = 0;
    setFixedSize(800, 600);
    showCurrentPhoto();
}

void PhotoGallery::previousPhoto() {
    currentIndex = (currentIndex - 1 + photoURLs.size()) % photoURLs.size();
    showCurrentPhoto();
}

void PhotoGallery::nextPhoto() {
    currentIndex = (currentIndex + 1) % photoURLs.size();
    showCurrentPhoto();
}

void PhotoGallery::loadPhotoURLsFromFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo:" << fileName;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << "URL cargada:" << line;
        photoURLs.push_back(line);
    }
}


void PhotoGallery::showCurrentPhoto() {
    if (currentIndex >= 0 && currentIndex < photoURLs.size()) {
        QPixmap pixmap(photoURLs[currentIndex]);
        if (!pixmap.isNull()) {
            pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatio);
            ((QLabel*)this->layout()->itemAt(0)->widget())->setPixmap(pixmap);
        }
    }
}
