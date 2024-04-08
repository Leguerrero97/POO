#include <iostream>
#include <string>

// Definición de la clase Persona
class Persona {
private:
    std::string nombre;

public:
    Persona(const std::string& nombre) : nombre(nombre) {}

    std::string getNombre() const {
        return nombre;
    }
};

// Definición de la clase Poste
class Poste {
private:
    float altura;
    float diametro;

public:
    Poste(float altura, float diametro) : altura(altura), diametro(diametro) {}

    float getAltura() const {
        return altura;
    }

    float getDiametro() const {
        return diametro;
    }
};

// Función genérica para imprimir descripción de cualquier objeto
template<typename T>
void imprimirDescripcion(const T& objeto) {
    std::cout << "Descripcion del objeto:\n";
}

// Especialización de la función imprimirDescripcion para la clase Persona
template<>
void imprimirDescripcion<Persona>(const Persona& persona) {
    std::cout << "Persona con nombre " << persona.getNombre() << "\n";
}

// Especialización de la función imprimirDescripcion para la clase Poste
template<>
void imprimirDescripcion<Poste>(const Poste& poste) {
    std::cout << "Poste con altura de " << poste.getAltura() << " metros y " << poste.getDiametro() << " cm de diametro\n";
}

int main() {
    // Crear objetos de la clase Persona
    Persona persona1("Lucrecia");
    Persona persona2("Juan");

    // Crear objetos de la clase Poste
    Poste poste1(8.0f, 15.0f);
    Poste poste2(10.0f, 20.0f);

    // Probar la función imprimirDescripcion con objetos de ambas clases
    imprimirDescripcion(persona1);
    imprimirDescripcion(persona2);
    imprimirDescripcion(poste1);
    imprimirDescripcion(poste2);

    return 0;
}
