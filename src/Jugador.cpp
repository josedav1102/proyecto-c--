#include "../include/Jugador.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre)
    : nombre(nombre), fila(4), columna(4), puntos(0) {
    // Posición inicial: centro del tablero (4,4)
    // Los puntos comienzan en 0
}


Jugador::~Jugador() {
}


std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getFila() const {
    return fila;
}

int Jugador::getColumna() const {
    return columna;
}

int Jugador::getPuntos() const {
    return puntos;
}


void Jugador::setFila(int f) {
    fila = f;
}

void Jugador::setColumna(int c) {
    columna = c;
}

void Jugador::setPuntos(int p) {
    if (p < 0) puntos = 0;  // No puede haber puntos negativos
    else puntos = p;
}


void Jugador::sumarPuntos(int cantidad) {
    puntos += cantidad;
    if (puntos < 0) puntos = 0;
}

void Jugador::restarPuntos(int cantidad) {
    puntos -= cantidad;
    if (puntos < 0) puntos = 0;
}

void Jugador::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}
