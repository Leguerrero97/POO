#include <iostream>
#include <vector>
#include <cstdlib> // para la función rand()
#include <ctime>   // para la función time()

// Función para encontrar la moda en un vector de enteros
int encontrarModa(const std::vector<int>& vec) {
    int moda = 0;
    int maxCount = 0;

    for (int i = 0; i < vec.size(); ++i) {
        int count = 0;
        for (int j = 0; j < vec.size(); ++j) {
            if (vec[j] == vec[i]) {
                ++count;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            moda = vec[i];
        }
    }

    return moda;
}

int main() {
    // Semilla para la función rand()
    std::srand(std::time(nullptr));

    // Crear un vector para contener los valores
    std::vector<int> valores;

    // Cargar 30 valores pseudoaleatorios entre 1 y 15
    for (int i = 0; i < 30; ++i) {
        int valor = std::rand() % 15 + 1; // Genera valores entre 1 y 15
        valores.push_back(valor);
    }

    // Mostrar los valores generados
    std::cout << "Valores generados:\n";
    for (int valor : valores) {
        std::cout << valor << " ";
    }
    std::cout << "\n";

    // Calcular y mostrar la moda
    int moda = encontrarModa(valores);
    std::cout << "La moda es: " << moda << "\n";

    return 0;
}
