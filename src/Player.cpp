#include "../include/Player.h"
#include <iostream>

Player::Player(const std::string& nombre)
    : nombre(nombre), fila(4), columna(4), puntos(0) {
    // Posición inicial: centro del tablero (4,4)
    // Los puntos comienzan en 0
}


Player::~Player() {
}


std::string Player::getNombre() const {
    return nombre;
}

int Player::getFila() const {
    return fila;
}

int Player::getColumna() const {
    return columna;
}

int Player::getPuntos() const {
    return puntos;
}


void Player::setFila(int f) {
    fila = f;
}

void Player::setColumna(int c) {
    columna = c;
}

void Player::setPuntos(int p) {
    if (p < 0) puntos = 0;  // No puede haber puntos negativos
    else puntos = p;
}


void Player::sumarPuntos(int cantidad) {
    puntos += cantidad;
    if (puntos < 0) puntos = 0;
}

void Player::restarPuntos(int cantidad) {
    puntos -= cantidad;
    if (puntos < 0) puntos = 0;
}

void Player::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}