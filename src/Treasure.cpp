//
// Created by Julian on 11/11/2025.
//
#include "Treasure.h"

Treasure::Treasure(TreasureType t) : type(t) {}

char Treasure::getSymbol() const {
    switch(type) {
        case TreasureType::RUBI: return 'R';
        case TreasureType::DIAMANTE: return 'D';
        case TreasureType::PERLA: return 'P';
        case TreasureType::AMBAR: return 'A';
        default: return '?';
    }
}

std::string Treasure::getName() const {
    switch(type) {
        case TreasureType::RUBI: return "Rubí";
        case TreasureType::DIAMANTE: return "Diamante";
        case TreasureType::PERLA: return "Perla";
        case TreasureType::AMBAR: return "Ámbar";
        default: return "Desconocido";
    }
}
