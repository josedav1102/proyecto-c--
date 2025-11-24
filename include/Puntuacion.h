#ifndef PUNTUACION_H
#define PUNTUACION_H

#include "Jugador.h"
#include <string>
#include <vector>
#include <map>

// ============================================
// Usa una Tabla Hash para almacenar el mejor puntaje por jugador
//   - Almacena Jugadores
//   - Se guarda/carga desde data/scores.txt (persistencia)
//   - Se llama desde main.cpp al final del juego
// ============================================
class Puntuacion {
private:
    std::map<std::string, int> puntajes;  // Hash Table: nombre -> mejor_puntuacion
    std::string archivoScores;

public:

    Puntuacion();


    ~Puntuacion();


    void agregarPuntaje(const std::string& nombre, int puntos);

    int obtenerPuntaje(const std::string& nombre) const;

    // PERSISTENCIA (archivo)
    bool cargarPuntajes();
    bool guardarPuntajes();

    // MOSTRAR INFORMACIÓN
    void mostrarTodos() const;
    void mostrarMejor() const;
};

#endif