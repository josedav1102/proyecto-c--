//
// Created by Julian on 11/11/2025.
//
//
// Created by Julian on 11/24/2025.
//

#include "Game.h"
#include "Utilities.h"
#include "Constants.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game() : laberinto(nullptr), jugador(nullptr), scoreboard(nullptr), jugando(false) {
    std::srand(std::time(nullptr));
}

Game::~Game() {
    // Guardar scores antes de destruir
    /**if (scoreboard) {
        scoreboard->guardarEnArchivo(ARCHIVO_SCORES);
    }**/

    delete laberinto;
    delete jugador;
    delete scoreboard;
}

void Game::iniciar() {
    cleanScreen();
    printHeader("EL JUEGO DE LOS LABERINTOS");

    std::cout << "\nBienvenido al juego de los laberintos!\n";
    std::cout << "Tu mision: encontrar los 10 tesoros ocultos.\n";
    std::cout << "Cada movimiento suma 1 punto al marcador.\n";
    std::cout << "¡Intenta completar el juego con el menor puntaje posible!\n\n";

    inicializarJuego();
    jugando = true;
    loop();
}

void Game::inicializarJuego() {
    // Solicitar nombre del jugador
    std::string nombre;
    std::cout << "Ingresa tu nombre: ";
    std::getline(std::cin, nombre);

    if (nombre.empty()) {
        nombre = "Jugador";
    }

    // Crear el laberinto
    std::cout << "\nGenerando laberinto...\n";
    laberinto = new Maze();

    // Crear jugador en posicion aleatoria que no sea muro
    int startRow, startCol;
    Node* startNode;

    do {
        startRow = std::rand() % FILAS;
        startCol = std::rand() % COLUMNAS;
        startNode = laberinto->getNode(startRow, startCol);
    } while (startNode && startNode->isWall());

    jugador = new Player(nombre);
    jugador->setPosicion(startRow, startCol);

    // Destapar posicion inicial
    startNode->discovered = true;

    // Crear scoreboard
    scoreboard = new Scoreboard();

    std::cout << "¡Laberinto generado!\n";
    std::cout << "Posicion inicial: (" << startRow << ", " << startCol << ")\n";

    pauseWithDuration(1500);
    mostrarAyuda();

    std::cout << "\nPresiona cualquier tecla para comenzar...";
    getKeyPress();
}

void Game::loop() {
    while (jugando) {
        cleanScreen();
        mostrarEstadisticas();
        laberinto->printMaze(jugador->getFila(), jugador->getColumna());

        std::cout << "\nComando: ";
        std::cout.flush();

        char input = getKeyPress();

        // AGREGAR: Filtrar caracteres no válidos
        if (input == '\n' || input == '\r' || input == ' ' || input == '\0') {
            continue;  // Ignorar y volver a pedir input
        }

        std::cout << input << std::endl;
        procesarInput(input);
    }

    terminar();
}


void Game::procesarInput(char input) {
    int filaActual = jugador->getFila();
    int colActual = jugador->getColumna();

    switch(input) {
        case 'W':
        case 'w':
            moverJugador(filaActual - 1, colActual);
            break;

        case 'S':
        case 's':
            moverJugador(filaActual + 1, colActual);
            break;

        case 'A':
        case 'a':
            moverJugador(filaActual, colActual - 1);
            break;

        case 'D':
        case 'd':
            moverJugador(filaActual, colActual + 1);
            break;

        case 'X':
        case 'x':
            usarTesoroX();
            break;

        case 'I':
        case 'i':
            mostrarInventario();
            break;

        case 'H':
        case 'h':
            mostrarAyuda();
            pauseWithDuration(2000);
            break;

        case 'Q':
        case 'q':
            jugando = false;
            break;

        default:
            std::cout << "\nComando no valido. Presiona 'H' para ver la ayuda.\n";
            pauseWithDuration(1000);
    }
}

void Game::moverJugador(int nuevaFila, int nuevaCol) {
    // Validar limites
    if (nuevaFila < 0 || nuevaFila >= FILAS || nuevaCol < 0 || nuevaCol >= COLUMNAS) {
        std::cout << "\n¡No puedes salir del laberinto!\n";
        pauseWithDuration(800);
        return;
    }

    Node* nodoDestino = laberinto->getNode(nuevaFila, nuevaCol);

    // Validar que no sea muro
    if (nodoDestino && nodoDestino->isWall()) {
        std::cout << "\n¡Hay un muro ahi!\n";
        pauseWithDuration(800);
        return;
    }

    // Mover al jugador
    jugador->setPosicion(nuevaFila, nuevaCol);
    jugador->sumarPuntos(1);  // +1 punto por movimiento

    // Destapar la casilla
    nodoDestino->discovered = true;

    // Verificar si hay tesoro
    if (nodoDestino->isTreasure()) {
        manejarTesoro(nodoDestino);
    }
}

void Game::manejarTesoro(Node* nodo) {
    // Determinar tipo de tesoro
    TreasureType tipo;
    switch(nodo->content) {
        case 'R': tipo = TreasureType::RUBI; break;
        case 'D': tipo = TreasureType::DIAMANTE; break;
        case 'P': tipo = TreasureType::PERLA; break;
        case 'A': tipo = TreasureType::AMBAR; break;
        default: return;
    }

    // Crear tesoro y agregarlo al inventario
    Treasure tesoro(tipo);
    jugador->agregarTesoro(tesoro);

    // Eliminar tesoro del tablero
    nodo->content = SIMBOLO_VACIO;

    pauseWithDuration(1500);

    // Verificar condicion de victoria
    verificarVictoria();
}

void Game::usarTesoroX() {
    if (!jugador->tieneTesoros()) {
        std::cout << "\nNo tienes tesoros para usar.\n";
        pauseWithDuration(1000);
        return;
    }

    // Usar el tesoro (pop de la pila)
    Treasure tesoroUsado = jugador->usarTesoro();

    std::cout << "\nReseteo del tablero en progreso...\n";
    pauseWithDuration(1000);

    // Resetear todas las casillas a ocultas
    laberinto->resetDiscovered();

    // Reaparece el tesoro en una nueva posicion aleatoria
    bool colocado = false;
    while (!colocado) {
        int row = std::rand() % FILAS;
        int col = std::rand() % COLUMNAS;
        Node* nodo = laberinto->getNode(row, col);

        if (nodo && nodo->content == SIMBOLO_OCULTO) {
            nodo->content = tesoroUsado.getSymbol();
            colocado = true;
        }
    }

    // Mantener la posicion del jugador destapada
    Node* nodoJugador = laberinto->getNode(jugador->getFila(), jugador->getColumna());
    if (nodoJugador) {
        nodoJugador->discovered = true;
    }

    std::cout << "¡Tablero reseteado! El tesoro reaparecio en otra ubicacion.\n";
    pauseWithDuration(1500);
}

void Game::verificarVictoria() {
    if (jugador->ganoElJuego()) {
        cleanScreen();
        printHeader("¡FELICIDADES! ¡GANASTE!");

        std::cout << "\n¡Encontraste los 10 tesoros!\n";
        std::cout << "Jugador: " << jugador->getNombre() << "\n";
        std::cout << "Puntaje final: " << jugador->getPuntos() << " movimientos\n\n";

        // Agregar al scoreboard
        scoreboard->agregarScore(jugador->getNombre(), jugador->getPuntos());
        scoreboard->guardarEnArchivo(ARCHIVO_SCORES);

        std::cout << "Tu puntuacion ha sido guardada.\n\n";

        pauseWithDuration(3000);

        // Mostrar tabla de puntuaciones
        scoreboard->mostrarScoreboard();

        std::cout << "\nPresiona cualquier tecla para salir...";
        getKeyPress();

        jugando = false;
    }
}

void Game::mostrarEstadisticas() const {
    printSeparator();
    std::cout << "Jugador: " << jugador->getNombre() << "\n";
    std::cout << "Posicion: (" << jugador->getFila() << ", " << jugador->getColumna() << ")\n";
    std::cout << "Movimientos: " << jugador->getPuntos() << "\n";
    std::cout << "Tesoros encontrados: " << jugador->contarTesoros() << "/10\n";
    printSeparator();
}

void Game::mostrarInventario() const {
    cleanScreen();
    printHeader("INVENTARIO");

    std::cout << "\nTesoros encontrados: " << jugador->contarTesoros() << "/10\n\n";

    if (jugador->tieneTesoros()) {
        Treasure ultimo = jugador->verUltimoTesoro();
        std::cout << "Ultimo tesoro: " << ultimo.getName() << " (" << ultimo.getSymbol() << ")\n";
        std::cout << "\nPuedes usar el ultimo tesoro con 'X' para resetear el tablero.\n";
    } else {
        std::cout << "Tu inventario esta vacio.\n";
    }

    std::cout << "\nPresiona cualquier tecla para continuar...";
    getKeyPress();
}

void Game::mostrarAyuda() const {
    cleanScreen();
    printHeader("AYUDA");

    std::cout << "\nCONTROLES:\n";
    printSeparator();
    std::cout << "W - Mover arriba\n";
    std::cout << "S - Mover abajo\n";
    std::cout << "A - Mover izquierda\n";
    std::cout << "D - Mover derecha\n";
    std::cout << "X - Usar tesoro (resetea el tablero)\n";
    std::cout << "I - Ver inventario\n";
    std::cout << "H - Mostrar esta ayuda\n";
    std::cout << "Q - Salir del juego\n\n";

    std::cout << "SIMBOLOS:\n";
    printSeparator();
    std::cout << "@ - Tu jugador\n";
    std::cout << "o - Casilla oculta\n";
    std::cout << "| - Muro (no puedes atravesarlo)\n";
    std::cout << "R - Rubi (tesoro)\n";
    std::cout << "D - Diamante (tesoro)\n";
    std::cout << "P - Perla (tesoro)\n";
    std::cout << "A - Ambar (tesoro)\n";
    std::cout << "# - Borde del laberinto\n\n";

    std::cout << "OBJETIVO:\n";
    printSeparator();
    std::cout << "Encuentra los 10 tesoros ocultos.\n";
    std::cout << "Cada movimiento suma 1 punto.\n";
    std::cout << "¡Menor puntaje es mejor!\n\n";
}

// src/Game.cpp - terminar() (línea ~320)

void Game::terminar() {
    cleanScreen();
    printHeader("GRACIAS POR JUGAR");

    std::cout << "\nEstadisticas finales:\n";
    printSeparator();
    std::cout << "Jugador: " << jugador->getNombre() << "\n";
    std::cout << "Movimientos realizados: " << jugador->getPuntos() << "\n";
    std::cout << "Tesoros encontrados: " << jugador->contarTesoros() << "/10\n\n";

    if (jugador->contarTesoros() < 10) {
        std::cout << "¡No completaste el juego! ¿Quieres intentarlo de nuevo?\n\n";
    }

    // Guardar progreso al salir
    std::cout << "Guardando progreso...\n";

    // DEBUG: Verificar condiciones
    std::cout << "[DEBUG] scoreboard existe: " << (scoreboard ? "SI" : "NO") << "\n";
    std::cout << "[DEBUG] tesoros encontrados: " << jugador->contarTesoros() << "\n";

    if (scoreboard && jugador->contarTesoros() > 0) {
        std::cout << "[DEBUG] Agregando score: " << jugador->getNombre()
                  << " con " << jugador->getPuntos() << " puntos\n";

        scoreboard->agregarScore(jugador->getNombre(), jugador->getPuntos());
        scoreboard->guardarEnArchivo(ARCHIVO_SCORES);

        std::cout << "Progreso guardado.\n";
    } else {
        std::cout << "[AVISO] No se guardó (sin tesoros o scoreboard nulo).\n";
    }

    pauseWithDuration(1500);
}
