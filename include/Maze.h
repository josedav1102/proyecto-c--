//
// Created by Julian on 11/11/2025.
//

#ifndef MAZE_H
#define MAZE_H

#include "Node.h"
#include <vector>

class Maze {
private:
    Node* start;                    // Primer nodo (0,0)
    const int SIZE = 9;
    std::vector<Node*> allNodes;    // Para fácil acceso y limpieza

    void buildMaze();               // Construir lista enlazada 9x9
    void connectNodes();            // Enlazar nodos
    void placeWalls();              // Colocar 16 muros
    void placeTreasures();          // Colocar 10 tesoros
    bool validateConnectivity();     // Verificar que todo sea alcanzable

public:
    Maze();
    ~Maze();

    Node* getNode(int row, int col);
    void printMaze(int playerRow, int playerCol);
    void resetDiscovered();         // Ocultar todas las casillas
    void regenerate();              // Regenerar tablero completo
};

#endif //MAZE_H
