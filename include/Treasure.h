//
// Created by Julian on 11/11/2025.
//

#ifndef TREASURE_H
#define TREASURE_H

#include <string>

enum class TreasureType {
    RUBI,      // 'R'
    DIAMANTE,  // 'D'
    PERLA,     // 'P'
    AMBAR      // 'A'
};

class Treasure {
public:
    TreasureType type;

    Treasure(TreasureType t);
    char getSymbol() const;
    std::string getName() const;
};

#endif //TREASURE_H
