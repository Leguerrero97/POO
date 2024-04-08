#include <iostream>
#include <QString>

// Definición de un espacio de nombres personalizado para la asignatura
namespace LautaroG {
    // Función para devolver el número de versión y la fecha de actualización

    QString getVersion() {
        QString version = "v4.11.0";
        QString fechaActualizacion = "2024/04/08";
        return version + " - " + fechaActualizacion;
    }
}

int main() {
    // Llamada a la función desde el espacio de nombres personalizado
    std::cout << "Informacion de la biblioteca:\n";
    std::cout << LautaroG::getVersion().toStdString() << std::endl; // Convertir QString a std::string para su impresión
    return 0;
}
