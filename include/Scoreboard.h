//
// Created by Julian on 11/11/2025.
//

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <string>
#include <unordered_map>
#include <vector>

struct Score {
    std::string nombre;
    int puntos;

    Score(const std::string& n, int p) : nombre(n), puntos(p) {}

    bool operator<(const Score& other) const {
        return puntos > other.puntos;  // Orden descendente
    }
};

class Scoreboard {
private:
    std::unordered_map<std::string, int> scores;

public:
    Scoreboard();
    ~Scoreboard();

    void agregarScore(const std::string& nombre, int puntos);
    std::vector<Score> obtenerTop10() const;
    void guardarEnArchivo(const std::string& archivo) const;
    void cargarDesdeArchivo(const std::string& archivo);
    void mostrarScoreboard() const;
};

#endif //SCOREBOARD_H

