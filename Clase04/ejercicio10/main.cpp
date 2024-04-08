#include <iostream>
#include <string>
#include <vector>

class Jugador {
private:
    int velocidad;
    int fuerza;
    std::string nombre;

public:
    // Constructor inicializando los atributos en 0 y "sin nombre"
    Jugador() : velocidad(0), fuerza(0), nombre("sin nombre") {}

    // Constructor con parámetros
    Jugador(int _velocidad, int _fuerza, const std::string& _nombre)
        : velocidad(_velocidad), fuerza(_fuerza), nombre(_nombre) {}

    // Destructor
    ~Jugador() {}

    // Métodos setters
    void setVelocidad(int _velocidad) { velocidad = _velocidad; }
    void setFuerza(int _fuerza) { fuerza = _fuerza; }
    void setNombre(const std::string& _nombre) { nombre = _nombre; }

    // Métodos getters
    int getVelocidad() const { return velocidad; }
    int getFuerza() const { return fuerza; }
    std::string getNombre() const { return nombre; }

    // Método para mostrar los datos del jugador
    void mostrarDatos() const {
        std::cout << "Nombre: " << nombre << ", Velocidad: " << velocidad << ", Fuerza: " << fuerza << std::endl;
    }
};

int main() {
    std::vector<Jugador> jugadores;

    // Crear 10 jugadores distintos utilizando el constructor con parámetros
    for (int i = 0; i < 10; ++i) {
        // Creamos un nombre único para cada jugador
        std::string nombreJugador = "Jugador" + std::to_string(i+1);

        // Creamos un jugador con valores específicos
        Jugador jugador(i * 10, i * 5, nombreJugador);

        // Añadimos el jugador al vector
        jugadores.push_back(jugador);
    }

    // Mostrar los datos de cada jugador
    for (const Jugador& jugador : jugadores) {
        jugador.mostrarDatos();
    }

    return 0;
}
