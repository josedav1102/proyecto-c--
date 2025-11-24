#ifndef Player_H
#define Player_H

#include <string>

#include "Pila_tesoros.h"

// ============================================
// Datos del Player: nombre y posicion
//   - Se mueve en el Laberinto
//   - Se guarda en Puntuacion
// ============================================
class Player {
private:
    std::string nombre;
    int fila;              // Posicion en el tablero (0-8)
    int columna;           // Posicion en el tablero (0-8)
    int puntos;            // Puntuación actual
    PilaTesoros inventario;

public:
    Player(const std::string& nombre);

    ~Player();

    std::string getNombre() const;
    int getFila() const;
    int getColumna() const;
    int getPuntos() const;

    void setFila(int f);
    void setColumna(int c);
    void setPuntos(int p);

    void sumarPuntos(int cantidad);    // Suma puntos (típicamente +1 por movimiento)
    void restarPuntos(int cantidad);   // Resta puntos
    void setPosicion(int f, int c);    // Cambia fila y columna de una vez

    void agregarTesoro(const Treasure& t);  // Push a la pila
    Treasure usarTesoro();                   // Pop de la pila
    int contarTesoros() const;               // Size de la pila
    bool tieneTesoros() const;               // Empty de la pila
    bool ganoElJuego() const;                // size() == 10
    Treasure verUltimoTesoro() const;        // Top de la pila
};

#endif // Player_H