#ifndef BOTON_H
#define BOTON_H

#include <QWidget>

class Boton : public QWidget
{
    Q_OBJECT

public:
    explicit Boton(QWidget *parent = nullptr);

    enum Color {
        Rojo,
        Azul,
        Verde,
        Magenta  // <-- Nuevo color agregado
    };

    void colorear(Color color);
    void setText(const QString &text);
    QString text() const;

signals:
    void signal_clic();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QColor m_color;
    QString m_text;
};

#endif // BOTON_H
