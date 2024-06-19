#include "visualizacionusuarios.h"
#include "manager.h"
#include "editarusuario.h" // Nuevo diálogo para editar usuarios
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

VisualizacionUsuarios::VisualizacionUsuarios(Manager *parent) : QWidget(parent), manager(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(4);
    treeWidget->setHeaderLabels(QStringList() << "ID" << "Nombre" << "Usuario" << "Contraseña");
    layout->addWidget(treeWidget);

    cerrarButton = new QPushButton("Cerrar Sesión");
    layout->addWidget(cerrarButton);

    connect(cerrarButton, &QPushButton::clicked, this, &VisualizacionUsuarios::cerrarVentana);
    connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &VisualizacionUsuarios::onItemDoubleClicked);

    cargarUsuarios();
}

void VisualizacionUsuarios::cargarUsuarios() {
    treeWidget->clear();

    QList<Usuario> usuarios = manager->db->obtenerUsuarios();

    for (const Usuario &usuario : usuarios) {
        QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
        item->setText(0, QString::number(usuario.id));
        item->setText(1, usuario.nombre);
        item->setText(2, usuario.usuario);
        item->setText(3, usuario.contrasena);
    }
}

void VisualizacionUsuarios::onItemDoubleClicked(QTreeWidgetItem *item, int column) {
    int id = item->text(0).toInt(); // Obtener el ID del usuario desde la primera columna
    Usuario usuario = manager->db->obtenerUsuarioPorId(id); // Suponiendo que tienes este método en AdminDB

    EditarUsuario dialogoEditar(this, usuario);
    if (dialogoEditar.exec() == QDialog::Accepted) {
        // Actualizar el usuario en la base de datos y en el QTreeWidget
        if (manager->db->editarUsuario(usuario.id, dialogoEditar.getNombre(), dialogoEditar.getUsuario(), dialogoEditar.getContrasena())) {
            cargarUsuarios();
        } else {
            QMessageBox::warning(this, "Error", "No se pudo editar el usuario.");
        }
    }
}
