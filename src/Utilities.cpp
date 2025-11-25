#include "Utilities.h"
#include <iostream>
#include <limits>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
#endif

void cleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printMessage(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
}

void pause() {
    std::cout << "\nPresiona Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void pauseWithDuration(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

void printHeader(const std::string& titulo) {
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "  " << titulo << "\n";
    std::cout << "========================================\n";
}

void printSeparator() {
    std::cout << "----------------------------------------\n";
}

char getKeyPress() {
#ifdef _WIN32
    char c = _getch();
    // En Windows, filtrar caracteres especiales
    if (c == 0 || c == -32) {  // Teclas especiales (flechas, etc)
        _getch();  // Consumir el segundo byte
        return '\0';  // Retornar nulo para ignorar
    }
    return c;
#else
    // Configurar terminal en modo raw
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    // Leer un carácter
    char c;
    read(STDIN_FILENO, &c, 1);

    // Restaurar terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

    return c;
#endif
}
