#include "widget.h"
#include "ui_widget.h"
#include <iostream>

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Conectar señales a slots (usando los nombres del archivo .ui)
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::agregarInstrumento);
    connect(ui->verStockButton, &QPushButton::clicked, this, &Widget::verStock);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Widget::on_comboBox_currentIndexChanged);

    // Configurar la interfaz inicial
    on_comboBox_currentIndexChanged(0); // Mostrar los campos adecuados para Guitarra al inicio
}

Widget::~Widget() {
    delete ui;

    // Liberar la memoria de los instrumentos creados dinámicamente
    for (Instrumento* instrumento : instrumentos) {
        delete instrumento;
    }
}

void Widget::agregarInstrumento() {
    Instrumento *nuevoInstrumento = nullptr;
    QString marca = ui->marcaLineEdit->text();
    bool precioOk = false;
    double precio = ui->lineEdit_2->text().toDouble(&precioOk);

    if (!precioOk || precio <= 0) {
        QMessageBox::warning(this, "Error", "Ingrese un precio válido.");
        return;
    }

    switch(ui->comboBox->currentIndex()) {
        case 0: { // Guitarra
            Guitarra *guitarra = new Guitarra();
            guitarra->marca = marca;
            guitarra->precio = precio;
            guitarra->cantidad_de_cuerdas = ui->spinBox->value();
            nuevoInstrumento = guitarra;
            break;
        }
        case 1: { // Viento
            Viento *viento = new Viento();
            viento->marca = marca;
            viento->precio = precio;
            viento->metal_usado = ui->metalLineEdit->text();
            nuevoInstrumento = viento;
            break;
        }
        case 2: { // Teclado
            Teclado *teclado = new Teclado();
            teclado->marca = marca;
            teclado->precio = precio;
            teclado->cantidad_de_teclas = ui->spinBox->value();
            nuevoInstrumento = teclado;
            break;
        }
    }

    if (nuevoInstrumento) {
        instrumentos.append(nuevoInstrumento);

        // Limpiar campos después de agregar
        ui->marcaLineEdit->clear();
        ui->lineEdit_2->clear();
        if (ui->spinBox->isVisible()) {
            ui->spinBox->setValue(0);
        }
        ui->metalLineEdit->clear();
    }
}

void Widget::verStock() {
    for (Instrumento* instrumento : instrumentos) {
        std::cout << "Instrumento: " << instrumento->marca.toStdString() << ", Precio: " << instrumento->precio << std::endl;
        instrumento->afinar();
    }
}

void Widget::on_comboBox_currentIndexChanged(int index) {
    // Mostrar/ocultar campos según el tipo de instrumento
    ui->spinBox->setVisible(index == 0 || index == 2);  // Guitarra o Teclado
    ui->metalLineEdit->setVisible(index == 1);         // Viento
}
