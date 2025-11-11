//
// Created by Julian on 11/11/2025.
//

#include "Node.h"

Node::Node(int r, int c)
    : up(nullptr), down(nullptr), left(nullptr), right(nullptr),
      content('o'), discovered(false), row(r), col(c) {}

void Node::reset() {
    if (content != '|' && content != 'R' && content != 'D' &&
        content != 'P' && content != 'A') {
        discovered = false;
        }
}

bool Node::isWall() const {
    return content == '|';
}

bool Node::isTreasure() const {
    return content == 'R' || content == 'D' ||
           content == 'P' || content == 'A';
}
