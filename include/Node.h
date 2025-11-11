//
// Created by Julian on 11/11/2025.
//

#ifndef NODE_H
#define NODE_H

class Node {
public:
    // Punteros de navegacion (lista múltiplemente enlazada)
    Node* up;
    Node* down;
    Node* left;
    Node* right;

    // Datos de la casilla
    char content;        // 'o', '|', 'P', 'R', 'D', 'P', 'A', ' '
    bool discovered;     // Si fue destapada
    int row;             // Posicion fila (0-8)
    int col;             // Posicion columna (0-8)

    // Constructor
    Node(int r, int c);

    // Métodos auxiliares
    void reset();        // Volver a ocultar
    bool isWall() const;
    bool isTreasure() const;
};

#endif //NODE_H
