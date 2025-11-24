#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

// ============================================
// Datos del jugador: nombre y posicion
//   - Se mueve en el Laberinto
//   - Se guarda en Puntuacion
// ============================================
class Jugador {
private:
    std::string nombre;
    int fila;              // Posicion en el tablero (0-8)
    int columna;           // Posicion en el tablero (0-8)
    int puntos;            // Puntuación actual

public:
    Jugador(const std::string& nombre);

    ~Jugador();

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
};

#endif // JUGADOR_H
