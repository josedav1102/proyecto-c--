#include "../include/Tesoro.h"
#include "../include/Constantes.h"
#include <iostream>


Tesoro::Tesoro(int t) : tipo(t) {
    switch(tipo) {
        case TIPO_RUBI:
            nombre = "Rubi";
            descripcion = "Reduce tus puntos a la mitad";
            break;
        case TIPO_DIAMANTE:
            nombre = "Diamante";
            descripcion = "Elimina 2 muros aleatorios";
            break;
        case TIPO_PERLA:
            nombre = "Perla";
            descripcion = "Aleatorio: puntos a 0 o puntos x2";
            break;
        case TIPO_AMBAR:
            nombre = "Ambar";
            descripcion = "Te teletransporta a una posicion aleatoria";
            break;
        default:
            nombre = "Desconocido";
            descripcion = "Sin efecto conocido";
    }
}


Tesoro::~Tesoro() {

}


int Tesoro::getTipo() const {
    return tipo;
}

std::string Tesoro::getNombre() const {
    return nombre;
}

std::string Tesoro::getDescripcion() const {
    return descripcion;
}


void Tesoro::mostrarInfo() const {
    std::cout << "  [" << nombre << "] - " << descripcion << std::endl;
}
