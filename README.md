# Laberinto Dinámico 2025-2

## ¿De qué trata el proyecto?
Construimos un generador de laberintos 9x9 totalmente dinámico que posiciona muros y tesoros de manera aleatoria, garantizando que siempre exista un camino accesible para el jugador. El objetivo es explorar el tablero, recolectar rubíes, diamantes, perlas y ámbar, y registrar la mejor puntuación posible.

## ¿Cómo llegamos a esta solución?
1. **Estructura enlazada del tablero**  
   Cada casilla es un `Node` con referencias arriba/abajo/izquierda/derecha (`include/Node.h`). Con esto modelamos el laberinto como una lista múltiplemente enlazada flexible que facilita recorrer y regenerar el mapa (`src/Maze.cpp`).

2. **Generación confiable**  
   El constructor de `Maze` crea los 81 nodos, conecta las casillas y ejecuta ciclos de generación hasta que un algoritmo BFS confirma que todos los tesoros pueden alcanzarse sin cruzar muros. Así evitamos laberintos imposibles y mantenemos partidas justas.

3. **Gestión de tesoros y puntajes**  
   Las clases `Treasure`, `Pila_tesoros` y `Scoreboard` (directorios `src/` e `include/`) organizan la recompensa de cada hallazgo, almacenan el historial y permiten mostrar los mejores resultados. Esta capa hace que el juego sea rejugable y medible.

4. **Experiencia del jugador**  
   Desde `main.cpp` inicializamos un jugador, ubicamos su posición aleatoria y mostramos el tablero revelando solo lo descubierto, lo que refuerza el carácter exploratorio del proyecto.

## Equipo de desarrollo
- DavidVal2
- josedav1102
- julianandresdev
