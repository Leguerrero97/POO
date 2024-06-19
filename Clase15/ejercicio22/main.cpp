#include <QtWidgets/QApplication>
#include <vector>
#include "instrumento.h"
#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    std::vector<Instrumento*> instrumentos;

    // Instanciar y agregar 5 instrumentos al vector
    instrumentos.push_back(new Guitarra(6, "Fender"));    // Guitarra con 6 cuerdas
    instrumentos.push_back(new Guitarra(12, "Gibson"));   // Guitarra con 12 cuerdas
    instrumentos.push_back(new Bateria(5, "Pearl"));     // Batería con 5 tambores
    instrumentos.push_back(new Teclado(61, "Yamaha"));    // Teclado con 61 teclas
    instrumentos.push_back(new Teclado(88, "Roland", 110)); // Teclado con 88 teclas y 110V

    // Recorrer el vector e imprimir información y sonido de cada instrumento
    for (Instrumento* instrumento : instrumentos) {
        instrumento->verMarca();
        instrumento->sonar();
        delete instrumento; // Liberar la memoria
    }

    return app.exec();
}
