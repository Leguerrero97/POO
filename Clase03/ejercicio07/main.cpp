#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // para std::sort

class Notebook {
private:
    std::string marca;
    std::string modelo;
    float precio;
    int cantidad;

public:
    // Constructor predeterminado
    Notebook() : marca(""), modelo(""), precio(0.0f), cantidad(0) {}

    // Constructor con parámetros
    Notebook(std::string marca, std::string modelo, float precio, int cantidad) : marca(marca), modelo(modelo), precio(precio), cantidad(cantidad) {}

    // Métodos para establecer y obtener los atributos
    void setMarca(std::string marca) { this->marca = marca; }
    void setModelo(std::string modelo) { this->modelo = modelo; }
    void setPrecio(float precio) { this->precio = precio; }
    void setCantidad(int cantidad) { this->cantidad = cantidad; }

    std::string getMarca() const { return marca; }
    std::string getModelo() const { return modelo; }
    float getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }

    // Método para calcular el valor total
    float calcularValorTotal() const { return precio * cantidad; }
};

// Comparador personalizado para ordenar los notebooks por precio de menor a mayor
bool compararPorPrecio(const Notebook& a, const Notebook& b) {
    return a.getPrecio() < b.getPrecio();
}

int main() {
    // Crear objetos de la clase Notebook
    Notebook notebook1("HP", "Pavilion", 899.99f, 10);
    Notebook notebook2("Dell", "Inspiron", 799.99f, 15);
    Notebook notebook3("Lenovo", "ThinkPad", 999.99f, 5);

    // Crear un vector y almacenar los objetos Notebook
    std::vector<Notebook> notebooks;
    notebooks.push_back(notebook1);
    notebooks.push_back(notebook2);
    notebooks.push_back(notebook3);

    // Ordenar los notebooks por precio de menor a mayor
    std::sort(notebooks.begin(), notebooks.end(), compararPorPrecio);

    // Imprimir la lista ordenada de notebooks
    std::cout << "Notebooks ordenados por precio de menor a mayor:\n";
    for (const auto& notebook : notebooks) {
        std::cout << "Marca: " << notebook.getMarca() << ", Modelo: " << notebook.getModelo() << ", Precio: " << notebook.getPrecio() << "\n";
    }

    return 0;
}
