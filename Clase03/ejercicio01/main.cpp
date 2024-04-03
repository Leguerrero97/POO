#include <iostream>
#include <ctime> // Incluir la librería para generar números aleatorios basados en el tiempo
#include <cstdlib> // Incluir la librería para funciones de manejo de memoria y de números aleatorios

int main() {
    // Semilla para la generación de números aleatorios basada en el tiempo actual
    srand(time(nullptr));
    std::cout << "10 numeros aleatorios en el intervalo [2, 20]:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 19 + 2; // Generar número aleatorio en el intervalo [2, 20]
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
