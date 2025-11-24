🧭 Laberinto Tesoros
¡Bienvenido al proyecto Laberinto Tesoros!
Un juego de consola en C++ donde deberás navegar un laberinto, enfrentar muros y recolectar tesoros usando estructuras avanzadas de datos.

📑 Índice
🎯 Descripción

⚙️ Características Principales

🧑‍💻 Integrantes del Equipo

🗺️ Estructura del Proyecto

🔧 Instalación y Ejecución

🕹️ Instrucciones de Juego

🔬 Estructuras de Datos Usadas

🏆 Puntaje y Tesoros

📌 Notas y Recomendaciones

🔗 Referencias

🎯 Descripción
Laberinto Tesoros es un juego académico de consola desarrollado en C++, donde el jugador se mueve por un laberinto de 9x9 casillas. El objetivo es recolectar 10 tesoros ocultos y lograr el mejor puntaje. El proyecto destaca por usar estructuras de datos no lineales (lista múltiplemente enlazada, pila y árbol/hash) para la lógica del juego, siguiendo criterios estrictos del curso.

⚙️ Características Principales
Tablero de 9x9 nodos (lista múltiplemente enlazada)

Movimientos en 4 direcciones por consola

10 tesoros ocultos con diferentes poderes

Muros y paredes que modifican la navegación

Tesoros gestionados con pila (LIFO)

Sistema de puntaje usando ABB o tabla hash

Persiste puntaje en archivos

Interfaz de usuario por consola sencilla y clara

🧑‍💻 Integrantes del Equipo
Persona 1: Estructuras del tablero y pila de tesoros

Persona 2: Gestor de tesoros, jugadores y sistema de puntuación

Persona 3: Utilidades, visualización, integración, documentación 

🗺️ Estructura del Proyecto
text
laberinto/
│
├─ include/
│  ├─ Constantes.h
│  ├─ Jugador.h
│  ├─ Laberinto.h
│  ├─ Nodo.h
│  ├─ Pila_tesoros.h
│  ├─ Puntuacion.h
│  ├─ Tesoro.h
│  └─ Utilidades.h
│
├─ src/
│  ├─ Jugador.cpp
│  ├─ Laberinto.cpp
│  ├─ Nodo.cpp
│  ├─ Pila_tesoros.cpp
│  ├─ Puntuacion.cpp
│  ├─ Tesoro.cpp
│  ├─ Utilidades.cpp
│  └─ main.cpp
│
├─ data/
│  └─ scores.txt
│
├─ README.md
├─ CMakeLists.txt
└─ .gitignore
🔧 Instalación y Ejecución
Requiere CMake y compilador C++17.

bash
# 1. Clona el repositorio
git clone https://github.com/usuario/laberinto-tesoros
cd laberinto-tesoros

# 2. Crea carpeta de compilación
mkdir build
cd build

# 3. Configura el proyecto
cmake ..

# 4. Compila el ejecutable
make

# 5. Ejecuta el juego
./laberinto
Si usas Windows, asegúrate de que el compilador soporta C++17.
Los datos se guardan en data/scores.txt.

🕹️ Instrucciones de Juego
Mueve al jugador con W (arriba), A (izquierda), S (abajo), D (derecha). 

T: Ver tesoros recolectados.

X: Usar el tesoro más reciente recolectado.

Q: Salir del juego.

Símbolos en el tablero:

P = Jugador

| = Muro (no atraviesas)

# = pared (borde)

o = Casilla oculta

<espacio> = Casilla libre/visitada

🔬 Estructuras de Datos Usadas
Lista múltiplemente enlazada: Cada casilla del laberinto conecta arriba, abajo, izquierda y derecha. Representa el tablero completo sin usar arrays/matrices.

Pila (LIFO): Almacena tesoros recogidos, permitiendo usar siempre el más nuevo primero.

ABB o Hash Table: Guarda el puntaje más bajo de cada jugador, con búsqueda y ordenación eficiente.

🏆 Puntaje y Tesoros
Moverse suma +1 punto (menos puntos = mejor).

Cada jugador solo tiene su mejor score guardado.

Poderes disponibles:

Tesoro	Efecto
Rubí	Divide los puntos actuales a la mitad
Diamante	Elimina 2 muros aleatorios
Perla	Aleatorio: puntos a 0 o puntos al doble
Ámbar	Teletransporta al jugador a una posición aleatoria
RECUERDA!!!!! Al usar un tesoro, la posición y la visibilidad del tablero cambian.
...