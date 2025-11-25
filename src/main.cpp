//
// Created by Julian on 11/11/2025.
//

#include "Game.h"
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#endif

int main() {
#ifdef _WIN32
    // Configurar codificación UTF-8 en Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    try {
        Game juego;
        juego.iniciar();
    } catch (const std::exception& e) {
        std::cerr << "Error fatal: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
