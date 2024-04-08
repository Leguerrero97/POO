#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Obtener la resolución de la pantalla
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    // Crear un QLabel con la misma resolución que la pantalla
    QLabel label;
    label.setGeometry(screenGeometry);

    // Cargar una imagen desde un archivo JPG
    QPixmap pixmap("C:/Users/Lautaro/Documents/Qt/Clase04/ejercicio12/gokonomiyajinja-garden.jpg"); // Ruta a la imagen

    // Mostrar la imagen en la QLabel
    label.setPixmap(pixmap);

    // Mostrar la QLabel maximizada
    label.showFullScreen();

    // Cerrar la QLabel y la aplicación después de 3 segundos
    QTimer::singleShot(3000, [&]() {
        label.close();
        app.quit();
    });

    return app.exec();
}
