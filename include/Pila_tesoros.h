//
// Created by Freddy Hurtado on 11/23/25.
//

#ifndef PILA_TESOROS_H
#define PILA_TESOROS_H

#include <stack>
#include <Treasure.h>
class PilaTesoros {
private:
    std::stack<Treasure> stack;
    public:
    void push(const Treasure& t);
    Treasure pop();
    Treasure top() const;
    bool empty() const;
    int size() const;
};

#endif