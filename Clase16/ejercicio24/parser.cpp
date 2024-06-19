#include "parser.h"
#include <QRegularExpression>
#include <QUrlQuery>

Parser::Parser(QObject *parent) : QObject(parent) {}

QVector<QUrl> Parser::parseHtmlForUrls(const QByteArray &html) {
    QVector<QUrl> urls;
    QString htmlString(html);

    // Expresión regular para encontrar URLs en atributos href
    QRegularExpression regex("href\\s*=\\s*([\"\'])([^\\1]*?)\\1", QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatchIterator matches = regex.globalMatch(htmlString);
    while (matches.hasNext()) {
        QRegularExpressionMatch match = matches.next();
        if (match.hasMatch()) {
            QString urlString = match.captured(2);

            // Manejo de URLs relativas
            if (urlString.startsWith("/")) {
                QUrl baseUrl = htmlReply->url();
                urlString = baseUrl.scheme() + "://" + baseUrl.host() + urlString;
            }

            QUrl url(urlString);
            if (url.isValid()) {
                urls.append(url);
            }
        }
    }

    // Expresiones regulares para encontrar URLs de imágenes, CSS y JavaScript
    QRegularExpression imgRegex("<img[^>]+src\\s*=\\s*([\"\'])([^\\1]*?)\\1");
    QRegularExpression cssRegex("<link[^>]+href\\s*=\\s*([\"\'])([^\\1]*?)\\1");
    QRegularExpression jsRegex("<script[^>]+src\\s*=\\s*([\"\'])([^\\1]*?)\\1");

    // Buscar URLs de imágenes
    matches = imgRegex.globalMatch(htmlString);
    while (matches.hasNext()) {
        QRegularExpressionMatch match = matches.next();
        if (match.hasMatch()) {
            QString urlString = match.captured(2);
            QUrl url(urlString);
            if (url.isValid()) {
                urls.append(url);
            }
        }
    }

    // Buscar URLs de CSS
    matches = cssRegex.globalMatch(htmlString);
    while (matches.hasNext()) {
        QRegularExpressionMatch match = matches.next();
        if (match.hasMatch()) {
            QString urlString = match.captured(2);
            QUrl url(urlString);
            if (url.isValid()) {
                urls.append(url);
            }
        }
    }

    // Buscar URLs de JavaScript
    matches = jsRegex.globalMatch(htmlString);
    while (matches.hasNext()) {
        QRegularExpressionMatch match = matches.next();
        if (match.hasMatch()) {
            QString urlString = match.captured(2);
            QUrl url(urlString);
            if (url.isValid()) {
                urls.append(url);
            }
        }
    }

    return urls;
}

