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
    instrumentos.push_back(new Guitarra(6, "Fender"));
    instrumentos.push_back(new Guitarra(12, "Gibson"));
    instrumentos.push_back(new Bateria(5, "Pearl"));
    instrumentos.push_back(new Teclado(61, "Yamaha"));
    instrumentos.push_back(new Teclado(88, "Roland", 110));

    // Ejemplo de uso de la función friend
    if (compararMarcas(*instrumentos[0], *instrumentos[1])) {
        qDebug() << "Los dos primeros instrumentos tienen la misma marca";
    }

    // Recorrer el vector e imprimir información y sonido de cada instrumento
    for (Instrumento* instrumento : instrumentos) {
        instrumento->verMarca();
        instrumento->sonar();
        delete instrumento; // Liberar la memoria
    }

    return app.exec();
}
