
#include "../include/Puntuacion.h"
#include "../include/Constantes.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Puntuacion::Puntuacion() : archivoScores(ARCHIVO_SCORES) {
    cargarPuntajes();  // Intenta cargar puntajes existentes
}

Puntuacion::~Puntuacion() {
    guardarPuntajes();  // Guarda puntajes antes de destruirse
}


// Solo guarda el MEJOR (menor) puntaje por jugador
void Puntuacion::agregarPuntaje(const std::string& nombre, int puntos) {
    // Si el jugador no existe en el mapa, lo crea con el puntaje actual
    if (puntajes.find(nombre) == puntajes.end()) {
        puntajes[nombre] = puntos;
        std::cout << "Nuevo jugador registrado: " << nombre << std::endl;
    }
    // Si existe y el nuevo puntaje es mejor (menor), actualiza
    else if (puntos < puntajes[nombre]) {
        puntajes[nombre] = puntos;
        std::cout << "Nuevo mejor puntaje para " << nombre << ": " << puntos << std::endl;
    }
    // Si no es mejor, no actualiza
    else {
        std::cout << "Puntaje no es mejor que el anterior (" << puntajes[nombre] << ")" << std::endl;
    }
}

// ============================================
// OBTENER PUNTAJE DE UN JUGADOR
// Retorna -1 si el jugador no existe
// ============================================
int Puntuacion::obtenerPuntaje(const std::string& nombre) const {
    auto it = puntajes.find(nombre);
    if (it != puntajes.end()) {
        return it->second;
    }
    return -1;  // Jugador no encontrado
}

// ============================================
// CARGAR PUNTAJES DESDE ARCHIVO
// Formato: nombre puntos (una línea por jugador)
// ============================================
bool Puntuacion::cargarPuntajes() {
    std::ifstream archivo(archivoScores);

    // Si el archivo no existe, es la primera vez - retorna true
    if (!archivo.is_open()) {
        std::cout << "Archivo de puntajes no encontrado. Se creará uno nuevo.\n" << std::endl;
        return true;
    }

    std::string nombre;
    int puntos;

    while (archivo >> nombre >> puntos) {
        puntajes[nombre] = puntos;
    }

    archivo.close();
    std::cout << "Puntajes cargados exitosamente.\n" << std::endl;
    return true;
}

// ============================================
// GUARDAR PUNTAJES EN ARCHIVO
// ============================================
bool Puntuacion::guardarPuntajes() {
    std::ofstream archivo(archivoScores);

    if (!archivo.is_open()) {
        std::cerr << "ERROR: No se pudo abrir " << archivoScores << " para escritura.\n" << std::endl;
        return false;
    }

    // Escribe cada puntaje en una línea: nombre puntos
    for (const auto& par : puntajes) {
        archivo << par.first << " " << par.second << "\n";
    }

    archivo.close();
    std::cout << "Puntajes guardados exitosamente.\n" << std::endl;
    return true;
}


// MOSTRAR TODOS LOS PUNTAJES ORDENADOS
void Puntuacion::mostrarTodos() const {
    if (puntajes.empty()) {
        std::cout << "\nNo hay puntajes registrados.\n" << std::endl;
        return;
    }

    std::cout << "\n========== TABLA DE PUNTAJES ==========" << std::endl;
    std::cout << "Posicion | Nombre           | Puntos" << std::endl;
    std::cout << "---------|------------------|-------" << std::endl;

    int pos = 1;
    for (const auto& par : puntajes) {
        printf("   %2d   | %-16s | %d\n", pos, par.first.c_str(), par.second);
        pos++;
    }

    std::cout << "======================================\n" << std::endl;
}

// MOSTRAR MEJOR PUNTAJE (mínimo)
void Puntuacion::mostrarMejor() const {
    if (puntajes.empty()) {
        std::cout << "No hay puntajes registrados.\n" << std::endl;
        return;
    }

    // Encuentra el puntaje mínimo
    auto mejor = std::min_element(
        puntajes.begin(),
        puntajes.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; }
    );

    std::cout << "\n=== MEJOR PUNTAJE ===" << std::endl;
    std::cout << "Jugador: " << mejor->first << std::endl;
    std::cout << "Puntos: " << mejor->second << std::endl;
    std::cout << "====================\n" << std::endl;
}
