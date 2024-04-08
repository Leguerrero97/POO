#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // para std::sort

int main() {
    // Crear un vector para contener objetos de la clase std::string
    std::vector<std::string> expresiones_idiomaticas;

    // Cargar 5 expresiones idiomaticas
    expresiones_idiomaticas.push_back("Pan comido");
    expresiones_idiomaticas.push_back("Mas vale tarde que nunca");
    expresiones_idiomaticas.push_back("Mas vale pajaro en mano que ciento volando");
    expresiones_idiomaticas.push_back("A caballo regalado no se le mira el diente");
    expresiones_idiomaticas.push_back("En boca cerrada no entran moscas");

    // Ordenar alfabaticamente
    std::sort(expresiones_idiomaticas.begin(), expresiones_idiomaticas.end());

    // Publicar por consola ordenado alfabéticamente
    std::cout << "Expresiones idiomaticas ordenadas alfabaticamente:\n";
    for (const std::string& expresion : expresiones_idiomaticas) {
        std::cout << expresion << "\n";
    }

    return 0;
}
