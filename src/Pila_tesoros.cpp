//
// Created by Freddy Hurtado on 11/23/25.
//

//
// Created by Freddy Hurtado on 11/23/25.
//

#include "Pila_tesoros.h"
#include <stdexcept>

void PilaTesoros::push(const Treasure& t) {
    stack.push(t);
}

Treasure PilaTesoros::pop() {
    if (stack.empty()) {
        throw std::runtime_error("Error: No hay tesoros en la pila");
    }

    Treasure t = stack.top();
    stack.pop();
    return t;
}

Treasure PilaTesoros::top() const {
    if (stack.empty()) {
        throw std::runtime_error("Error: No hay tesoros en la pila");
    }

    return stack.top();
}

bool PilaTesoros::empty() const {
    return stack.empty();
}

int PilaTesoros::size() const {
    return stack.size();
}
