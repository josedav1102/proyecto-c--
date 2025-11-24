#include "../include/utilidades.h"
#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void imprimirMensaje(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
}

void pausar() {
    std::cout << "\nPresiona ENTER para continuar...";
    std::cin.ignore();
    std::cin.get();
}
