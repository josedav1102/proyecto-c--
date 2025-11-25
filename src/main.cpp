//
// Created by Julian on 11/11/2025.
//

#include <iostream>
#include "Maze.h"

int main() {
    std::cout << "=== Prueba de Generacion del Laberinto ===\n";

    Maze maze;

    // Posicion inicial del jugador (aleatoria)
    int playerRow = std::rand() % 9;
    int playerCol = std::rand() % 9;

    std::cout << "Jugador en posicion (" << playerRow << ", " << playerCol << ")\n";
    maze.printMaze(playerRow, playerCol);

    return 0;
}
