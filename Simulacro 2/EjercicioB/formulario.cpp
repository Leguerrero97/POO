#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Guitarra");
    ui->comboBox->addItem("Viento");
    ui->comboBox->addItem("Teclado");

    connect(ui->agregarButton, &QPushButton::clicked, this, &Formulario::agregarInstrumento);
    connect(ui->verStockButton, &QPushButton::clicked, this, &Formulario::verStock);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Formulario::on_comboBox_currentIndexChanged);

    on_comboBox_currentIndexChanged(0);
}

Formulario::~Formulario() {
    delete ui;
    for(auto instrumento : instrumentos) {
        delete instrumento;
    }
}

void Formulario::agregarInstrumento() {
    Instrumento *nuevoInstrumento = nullptr;
    QString marca = ui->marcaLineEdit->text();
    double precio = ui->precioLineEdit->text().toDouble();

    switch(ui->comboBox->currentIndex()) {
        case 0: { // Guitarra
            Guitarra *guitarra = new Guitarra();
            guitarra->marca = marca;
            guitarra->precio = precio;
            guitarra->cantidad_de_cuerdas = ui->cantidadSpinBox->value();
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
            teclado->cantidad_de_teclas = ui->cantidadSpinBox->value();
            nuevoInstrumento = teclado;
            break;
        }
    }

    if(nuevoInstrumento) {
        instrumentos.append(nuevoInstrumento);
    }
}

void Formulario::verStock() {
    for(auto instrumento : instrumentos) {
        std::cout << "Instrumento: " << instrumento->marca.toStdString() << ", Precio: " << instrumento->precio << std::endl;
        instrumento->afinar();
    }
}

void Formulario::on_comboBox_currentIndexChanged(int index) {
    ui->marcaLineEdit->clear();
    ui->precioLineEdit->clear();
    ui->cantidadSpinBox->setValue(0);
    ui->metalLineEdit->clear();

    ui->marcaLineEdit->setEnabled(true);
    ui->precioLineEdit->setEnabled(true);
    ui->cantidadSpinBox->setEnabled(false);
    ui->metalLineEdit->setEnabled(false);

    switch(index) {
        case 0: // Guitarra
            ui->cantidadSpinBox->setEnabled(true);
            ui->cantidadSpinBox->setMinimum(1);
            ui->cantidadSpinBox->setMaximum(12);
            ui->cantidadSpinBox->setSuffix(" cuerdas");
            break;
        case 1: // Viento
            ui->metalLineEdit->setEnabled(true);
            ui->metalLineEdit->setPlaceholderText("Metal Usado");
            break;
        case 2: // Teclado
            ui->cantidadSpinBox->setEnabled(true);
            ui->cantidadSpinBox->setMinimum(25);
            ui->cantidadSpinBox->setMaximum(88);
            ui->cantidadSpinBox->setSuffix(" teclas");
            break;
    }
}
