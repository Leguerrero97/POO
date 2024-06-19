#ifndef PARSER_H
#define PARSER_H

#include <QObject>
#include <QByteArray>
#include <QVector>
#include <QUrl>

class Parser : public QObject {
    Q_OBJECT

public:
    explicit Parser(QObject *parent = nullptr);

public slots:
    QVector<QUrl> parseHtmlForUrls(const QByteArray &html);
};

#endif // PARSER_H

