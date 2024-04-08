#include <iostream>

template <class T>
void imprimirArreglo(T *v, int cantidad) {
    // Imprimir el arreglo en el orden en que está
    for (int i = 0; i < cantidad; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void imprimirArregloInverso(T *v, int cantidad) {
    // Imprimir el arreglo en orden inverso
    for (int i = cantidad - 1; i >= 0; --i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void ordenarInsercion(T *v, int cantidad) {
    // Ordenar el arreglo utilizando el método de inserción
    for (int i = 1; i < cantidad; ++i) {
        T temp = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > temp) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = temp;
    }
}

int main() {
    // Ejemplo con arreglo de enteros
    int arrInt[] = {5, 2, 9, 1, 7};
    int cantidadInt = sizeof(arrInt) / sizeof(arrInt[0]);
    ordenarInsercion(arrInt, cantidadInt); // Ordenar de menor a mayor
    std::cout << "Arreglo ordenado de menor a mayor: ";
    imprimirArreglo(arrInt, cantidadInt);
    std::cout << "Arreglo ordenado de mayor a menor: ";
    imprimirArregloInverso(arrInt, cantidadInt);

    // Ejemplo con arreglo de flotantes
    float arrFloat[] = {3.5, 1.2, 8.9, 2.7, 6.4};
    int cantidadFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);
    ordenarInsercion(arrFloat, cantidadFloat); // Ordenar de menor a mayor
    std::cout << "Arreglo ordenado de menor a mayor: ";
    imprimirArreglo(arrFloat, cantidadFloat);
    std::cout << "Arreglo ordenado de mayor a menor: ";
    imprimirArregloInverso(arrFloat, cantidadFloat);

    return 0;
}
