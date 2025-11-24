#ifndef TESORO_H
#define TESORO_H

#include <string>

// ============================================
// CLASE TESORO
// Representa un tesoro con su tipo, nombre y descripción
// Se usa en la Pila_tesoros 
// ============================================
class Tesoro {
private:
    int tipo;              // 1 = Rubi, 2 = Diamante, 3 = Perla, 4 = Ambar
    std::string nombre;
    std::string descripcion;

public:
    // Constructor
    Tesoro(int t);
    
    // Destructor
    ~Tesoro();
    
    int getTipo() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    
    // MÉTODO ESPECIAL - Para mostrar info bonita en pantalla
    void mostrarInfo() const;
};

#endif 
