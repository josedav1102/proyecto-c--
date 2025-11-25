#include "Scoreboard.h"
#include "Utilities.h"
#include "Constants.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cstdio>

Scoreboard::Scoreboard() {
    cargarDesdeArchivo(ARCHIVO_SCORES);
}

Scoreboard::~Scoreboard() {
    // El unordered_map se limpia automáticamente
}

void Scoreboard::agregarScore(const std::string& nombre, int puntos) {
    // Si el jugador ya existe, solo actualizar si el nuevo puntaje es mejor (menor)
    if (scores.find(nombre) != scores.end()) {
        if (puntos < scores[nombre]) {
            scores[nombre] = puntos;
        }
    } else {
        scores[nombre] = puntos;
    }
}

std::vector<Score> Scoreboard::obtenerTop10() const {
    // Convertir el map a vector de Score
    std::vector<Score> ranking;

    for (const auto& par : scores) {
        // Usar emplace_back para construir Score directamente
        ranking.emplace_back(par.first, par.second);
    }

    // Ordenar por puntos (menor a mayor, porque menor puntaje es mejor)
    std::sort(ranking.begin(), ranking.end());

    // Retornar solo top 10
    if (ranking.size() > 10) {
        ranking.resize(10);
    }

    return ranking;
}

void Scoreboard::guardarEnArchivo(const std::string& archivo) const {
    if (scores.empty()) {
        return;
    }

    FILE* file = fopen(archivo.c_str(), "w");

    if (!file) {
        return;
    }

    for (const auto& par : scores) {
        fprintf(file, "%s,%d\n", par.first.c_str(), par.second);
    }

    fflush(file);
    fclose(file);
}

void Scoreboard::cargarDesdeArchivo(const std::string& archivo) {
    std::ifstream file(archivo);

    if (!file.is_open()) {
        return;
    }

    std::string linea;
    while (std::getline(file, linea)) {
        size_t pos = linea.find(',');
        if (pos != std::string::npos) {
            std::string nombre = linea.substr(0, pos);
            int puntos = std::stoi(linea.substr(pos + 1));
            scores[nombre] = puntos;
        }
    }

    file.close();
}

void Scoreboard::mostrarScoreboard() const {
    cleanScreen();
    printHeader("TABLA DE PUNTUACIONES");

    std::vector<Score> top10 = obtenerTop10();

    if (top10.empty()) {
        std::cout << "\nAun no hay puntuaciones registradas.\n";
        std::cout << "¡Se el primero en completar el juego!\n\n";
        return;
    }

    std::cout << "\n";
    std::cout << std::left << std::setw(5) << "#"
              << std::setw(25) << "Jugador"
              << std::setw(10) << "Movimientos" << "\n";
    printSeparator();

    for (size_t i = 0; i < top10.size(); i++) {
        std::cout << std::left << std::setw(5) << (i + 1)
                  << std::setw(25) << top10[i].nombre
                  << std::setw(10) << top10[i].puntos << "\n";
    }

    std::cout << "\n";
}
