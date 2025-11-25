//
// Created by Julian on 11/11/2025.
//

#ifndef GAME_H
#define GAME_H

#include "Maze.h"
#include "Player.h"
#include "Scoreboard.h"

class Game {
private:
    Maze* laberinto;
    Player* jugador;
    Scoreboard* scoreboard;
    bool jugando;

    void inicializarJuego();
    void procesarInput(char input);
    void moverJugador(int nuevaFila, int nuevaCol);
    void manejarTesoro(Node* nodo);
    void usarTesoroX();
    void verificarVictoria();
    void mostrarEstadisticas() const;
    void mostrarInventario() const;
    void mostrarAyuda() const;
    void mostrarControlesBasicos() const;

public:
    Game();
    ~Game();

    void iniciar();
    void loop();
    void terminar();

    void activarCheatVictoria();
};

#endif //GAME_H
