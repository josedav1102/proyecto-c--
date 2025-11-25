//
// Created by Julian on 11/11/2025.
//
#include "Maze.h"
#include <Constants.h>
#include <ctime>
#include <iostream>
#include <queue>
#include <set>

Maze::Maze() : start(nullptr) {
    std::srand(std::time(nullptr));
    buildMaze();
}

Maze::~Maze() {
    for (Node* node : allNodes) {
        delete node;
    }
}

void Maze::buildMaze() {
    // Crear 81 nodos (9x9)
    for (int i = 0; i < COLUMNAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            Node* node = new Node(i, j);
            allNodes.push_back(node);
        }
    }

    if (!allNodes.empty()) {
        start = allNodes[0];
    }

    connectNodes();

    // Generar hasta conseguir un laberinto válido
    do {
        // Limpiar configuracion anterior
        for (Node* node : allNodes) {
            node->content = 'o';
            node->discovered = false;
        }

        placeWalls();
        placeTreasures();
    } while (!validateConnectivity());
}

void Maze::connectNodes() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int index = i * COLUMNAS + j;
            Node* current = allNodes[index];

            // Conectar arriba
            if (i > 0) {
                current->up = allNodes[(i-1) * COLUMNAS + j];
            }

            // Conectar abajo
            if (i < COLUMNAS - 1) {
                current->down = allNodes[(i+1) * COLUMNAS + j];
            }

            // Conectar izquierda
            if (j > 0) {
                current->left = allNodes[i * COLUMNAS + (j-1)];
            }

            // Conectar derecha
            if (j < COLUMNAS - 1) {
                current->right = allNodes[i * COLUMNAS + (j+1)];
            }
        }
    }
}

Node* Maze::getNode(int row, int col) {
    if (row < 0 || row >= COLUMNAS || col < 0 || col >= COLUMNAS) {
        return nullptr;
    }
    return allNodes[row * COLUMNAS + col];
}
void Maze::placeWalls() {
    int wallsPlaced = 0;

    while (wallsPlaced < 16) {
        int row = std::rand() % COLUMNAS;
        int col = std::rand() % COLUMNAS;
        Node* node = getNode(row, col);

        if (node && node->content == 'o') {
            node->content = '|';
            wallsPlaced++;
        }
    }
}

void Maze::placeTreasures() {
    // Distribuir 10 tesoros: 3 Rubí, 3 Diamante, 2 Perla, 2 Ámbar
    char treasures[] = {'R', 'R', 'R', 'D', 'D', 'D', 'P', 'P', 'A', 'A'};

    for (int i = 0; i < 10; i++) {
        bool placed = false;

        while (!placed) {
            int row = std::rand() % COLUMNAS;
            int col = std::rand() % COLUMNAS;
            Node* node = getNode(row, col);

            if (node && node->content == 'o') {
                node->content = treasures[i];
                placed = true;
            }
        }
    }
}

bool Maze::validateConnectivity() {
    // BFS para verificar que todos los tesoros sean alcanzables
    std::queue<Node*> queue;
    std::set<Node*> visited;
    int treasuresFound = 0;

    // Encontrar una posicion inicial válida (no muro)
    Node* startNode = nullptr;
    for (Node* node : allNodes) {
        if (node->content != '|') {
            startNode = node;
            break;
        }
    }

    if (!startNode) return false;

    queue.push(startNode);
    visited.insert(startNode);

    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop();

        if (current->isTreasure()) {
            treasuresFound++;
        }

        // Explorar vecinos
        Node* neighbors[] = {current->up, current->down, current->left, current->right};

        for (Node* neighbor : neighbors) {
            if (neighbor && neighbor->content != '|' &&
                visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }

    // Si encontramos los 10 tesoros, el laberinto es válido
    return treasuresFound == 10;
}

void Maze::resetDiscovered() {
    for (Node* node : allNodes) {
        node->reset();
    }
}

void Maze::printMaze(int playerRow, int playerCol) {
    // Borde superior
    std::cout << "\n  ";
    for (int j = 0; j < COLUMNAS; j++) {
        std::cout << " " << j << " ";
    }
    std::cout << "\n  ";
    for (int j = 0; j < COLUMNAS + 2; j++) {
        std::cout << "###";
    }
    std::cout << "\n";

    // Contenido del tablero
    for (int i = 0; i < COLUMNAS; i++) {
        std::cout << i << " #";

        for (int j = 0; j < COLUMNAS; j++) {
            Node* node = getNode(i, j);

            if (i == playerRow && j == playerCol) {
                std::cout << " " << SIMBOLO_JUGADOR << " ";
            } else if (node->discovered || node->isWall() || node->isTreasure()) {
                std::cout << " " << node->content << " ";
            } else {
                std::cout << " o ";
            }
        }

        std::cout << "#\n";
    }

    // Borde inferior
    std::cout << "  ";
    for (int j = 0; j < COLUMNAS + 2; j++) {
        std::cout << "###";
    }
    std::cout << "\n\n";
}

