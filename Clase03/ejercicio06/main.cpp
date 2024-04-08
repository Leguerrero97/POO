#include <iostream>
#include <string>

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

int main() {
    // Crear objetos de la clase Notebook
    Notebook notebook1("HP", "Pavilion", 899.99f, 10);
    Notebook notebook2("Dell", "Inspiron", 799.99f, 15);

    // Imprimir información sobre los notebooks
    std::cout << "Notebook 1:\n";
    std::cout << "Marca: " << notebook1.getMarca() << "\n";
    std::cout << "Modelo: " << notebook1.getModelo() << "\n";
    std::cout << "Precio: " << notebook1.getPrecio() << "\n";
    std::cout << "Cantidad: " << notebook1.getCantidad() << "\n";
    std::cout << "Valor total: " << notebook1.calcularValorTotal() << "\n\n";

    std::cout << "Notebook 2:\n";
    std::cout << "Marca: " << notebook2.getMarca() << "\n";
    std::cout << "Modelo: " << notebook2.getModelo() << "\n";
    std::cout << "Precio: " << notebook2.getPrecio() << "\n";
    std::cout << "Cantidad: " << notebook2.getCantidad() << "\n";
    std::cout << "Valor total: " << notebook2.calcularValorTotal() << "\n";

    return 0;
}
