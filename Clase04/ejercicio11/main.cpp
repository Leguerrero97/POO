#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout> // Se agrega para utilizar QVBoxLayout

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Creamos un QWidget principal que será el contenedor de los elementos
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Creamos y configuramos los elementos
    QLabel label("Etiqueta");
    QPushButton button("Botón");
    QLineEdit lineEdit;

    // Añadimos los elementos al layout
    layout->addWidget(&label);
    layout->addWidget(&button);
    layout->addWidget(&lineEdit);

    // Mostramos la ventana
    window.show();

    return app.exec();
}
