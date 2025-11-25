
***

# 📝 README.md - Versión Premium

<div align="center">

# 🏰 Laberinto Dinámico - Juego de Aventuras en C++

### *Explora, Recolecta, Conquista* 🗺️

[![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-3.10+-064F8C?style=for-the-badge&logo=cmake&logoColor=white)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-Academic-green?style=for-the-badge)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey?style=for-the-badge)](https://github.com/josedav1102/proyecto-c--)

<img src="https://img.icons8.com/color/200/000000/treasure-map.png" alt="Treasure Map" width="150"/>

*Un proyecto de Estructuras de Datos desarrollado en 2025-2*

[🎮 Características](#-características-principales) • [🚀 Instalación](#-instalación-rápida) • [📖 Cómo Jugar](#-cómo-jugar) • [🏗️ Arquitectura](#%EF%B8%8F-arquitectura-técnica) • [👥 Equipo](#-equipo-de-desarrollo)

</div>

---

## 🎯 Sobre el Proyecto

> **Laberinto Dinámico** es un juego de exploración en consola donde debes encontrar 10 tesoros ocultos en un laberinto generado proceduralmente de 9×9 casillas. Cada partida es única gracias a nuestro generador aleatorio con validación BFS.

### ✨ Lo que hace especial a este proyecto

- 🔄 **Generación 100% Aleatoria** - Nunca el mismo laberinto dos veces
- 🛡️ **Siempre Resoluble** - Algoritmo BFS garantiza accesibilidad
- 💎 **4 Tipos de Tesoros** - Rubí, Diamante, Perla y Ámbar
- 🏆 **Sistema de Rankings** - Compite por el menor número de movimientos
- 💾 **Persistencia de Datos** - Tus mejores puntuaciones se guardan automáticamente
- 🖥️ **Cross-Platform** - Funciona en Windows, macOS y Linux

---

## 🎮 Características Principales

<table>
<tr>
<td width="50%">

### 🏗️ Estructuras de Datos

- **Lista Enlazada Múltiple** (4 conexiones/nodo)
- **Pila LIFO** para inventario de tesoros
- **Hash Table** para scoreboard (`O(1)`)
- **BFS** para validación de conectividad

</td>
<td width="50%">

### 🎨 Características del Juego

- Input sin presionar Enter
- Interfaz visual en consola
- Sistema de niebla de guerra (casillas ocultas)
- Mecánica especial: usar tesoros para resetear
- Cheat code para testing

</td>
</tr>
</table>

---

## 🚀 Instalación Rápida

### 📋 Requisitos Previos

```

✅ CMake 3.10 o superior
✅ Compilador C++17 (g++, clang, MSVC)
✅ Git

```

### 💻 Instalación por Plataforma

<details>
<summary><b>🪟 Windows</b></summary>

```


# Clonar repositorio

git clone https://github.com/josedav1102/proyecto-c--.git
cd proyecto-c--

# Configurar CMake

mkdir cmake-build-debug
cd cmake-build-debug
cmake ..

# Compilar

cmake --build . --config Release

# ¡Jugar!

laberinto.exe

```

</details>

<details>
<summary><b>🍎 macOS</b></summary>

```


# Clonar repositorio

git clone https://github.com/josedav1102/proyecto-c--.git
cd proyecto-c--

# Configurar y compilar

mkdir cmake-build-debug \&\& cd cmake-build-debug
cmake ..
make

# ¡Jugar!

./laberinto

```

</details>

<details>
<summary><b>🐧 Linux</b></summary>

```


# Clonar repositorio

git clone https://github.com/josedav1102/proyecto-c--.git
cd proyecto-c--

# Configurar y compilar

mkdir cmake-build-debug \&\& cd cmake-build-debug
cmake ..
make -j4  \# Compilación paralela

# ¡Jugar!

./laberinto

```

</details>

---

## 📖 Cómo Jugar

### 🎮 Controles

<div align="center">

| Tecla | Acción | Descripción |
|:-----:|:------:|:------------|
| <kbd>W</kbd> | ⬆️ | Mover hacia arriba |
| <kbd>S</kbd> | ⬇️ | Mover hacia abajo |
| <kbd>A</kbd> | ⬅️ | Mover a la izquierda |
| <kbd>D</kbd> | ➡️ | Mover a la derecha |
| <kbd>X</kbd> | 🔄 | Usar tesoro (resetea tablero) |
| <kbd>I</kbd> | 🎒 | Ver inventario |
| <kbd>H</kbd> | ❓ | Mostrar ayuda |
| <kbd>Q</kbd> | 🚪 | Salir del juego |
| <kbd>G</kbd> | 🎁 | Cheat (solo testing) |

</div>

### 🗺️ Símbolos del Tablero

```

@  - Tu jugador (aquí estás)
o  - Casilla oculta (por explorar)
|  - Muro (¡no puedes pasar!)
R  - 💎 Rubí (tesoro)
D  - 💠 Diamante (tesoro)
P  - ⚪ Perla (tesoro)
A  - 🟡 Ámbar (tesoro)

# - Borde del laberinto

```

### 🎯 Objetivo

```

🏆 Encuentra los 10 tesoros escondidos
📊 Cada movimiento suma 1 punto
⚡ Menor puntaje = Mejor jugador
💾 Tu mejor score se guarda automáticamente

```

### 🎪 Ejemplo de Partida

```

----------------------------------------
Jugador: Julian
Posicion: (8, 0)
Movimientos: 0
Tesoros encontrados: 0/10
----------------------------------------

   0  1  2  3  4  5  6  7  8
  #################################
0 # o  o  o  |  o  o  o  o  D #
1 # |  |  o  P  o  |  o  o  A #
2 # o  o  D  R  o  R  o  |  o #
3 # |  o  o  o  o  o  o  o  o #
4 # o  o  |  o  o  o  o  D  o #
5 # o  o  |  |  o  o  o  o  o #
6 # o  o  |  o  |  o  |  o  o #
7 # o  |  o  o  o  o  P  R  | #
8 # @  A  o  o  o  o  o  |  | #
  #################################


[W/A/S/D: Mover] [X: Usar tesoro] [I: Inventario] [H: Ayuda] [Q: Salir]

Comando: _

```

---

## 🏗️ Arquitectura Técnica

### 📊 Complejidad Algorítmica

<table>
<tr>
<td><b>Operación</b></td>
<td><b>Estructura</b></td>
<td><b>Complejidad</b></td>
</tr>
<tr>
<td>Acceso a nodo vecino</td>
<td>Lista Enlazada</td>
<td><code>O(1)</code></td>
</tr>
<tr>
<td>Push/Pop tesoro</td>
<td>Pila LIFO</td>
<td><code>O(1)</code></td>
</tr>
<tr>
<td>Guardar/Buscar score</td>
<td>Hash Table</td>
<td><code>O(1)</code> promedio</td>
</tr>
<tr>
<td>Validar laberinto</td>
<td>BFS</td>
<td><code>O(V + E)</code></td>
</tr>
<tr>
<td>Ordenar Top 10</td>
<td>Sort</td>
<td><code>O(n log n)</code></td>
</tr>
</table>

> **Nota:** V = 81 nodos, E ≈ 324 aristas (4 por nodo)

### 🧩 Estructura del Proyecto

```

proyecto-c--/
│
├── 📂 include/                 \# Headers (.h)
│   ├── Constants.h            \# Constantes del juego
│   ├── Game.h                 \# Controlador principal
│   ├── Maze.h                 \# Generador de laberintos
│   ├── Node.h                 \# Nodo de lista enlazada
│   ├── Pila_tesoros.h         \# Stack de tesoros
│   ├── Player.h               \# Clase jugador
│   ├── Scoreboard.h           \# Sistema de puntajes
│   ├── Treasure.h             \# Tipos de tesoros
│   └── Utilities.h            \# Funciones auxiliares
│
├── 📂 src/                     \# Implementaciones (.cpp)
│   ├── Game.cpp               \# Lógica del juego
│   ├── main.cpp               \# Punto de entrada
│   ├── Maze.cpp               \# Generación + BFS
│   ├── Node.cpp               \# Operaciones de nodo
│   ├── Pila_tesoros.cpp       \# Implementación de pila
│   ├── Player.cpp             \# Gestión del jugador
│   ├── Scoreboard.cpp         \# Hash Table + persistencia
│   ├── Treasure.cpp           \# Tesoros
│   └── Utilities.cpp          \# Utils cross-platform
│
├── 📄 CMakeLists.txt          \# Configuración CMake
├── 📄 README.md               \# Este archivo
└── 📄 .gitignore              \# Archivos ignorados

```

### 🔄 Flujo del Programa

```

graph TD
A[main.cpp] --> B[Game::iniciar]
B --> C[Inicializar Maze]
C --> D[BFS Validation]
D --> E{¿Válido?}
E -->|No| C
E -->|Sí| F[Game Loop]
F --> G[Input del Usuario]
G --> H{Comando}
H -->|WASD| I[Mover Jugador]
H -->|X| J[Usar Tesoro]
H -->|I| K[Ver Inventario]
H -->|Q| L[Terminar]
I --> M{¿Tesoro encontrado?}
M -->|Sí| N[Agregar a Pila]
N --> O{¿10 tesoros?}
O -->|Sí| P[Victoria]
O -->|No| F
M -->|No| F
P --> Q[Guardar Score]
Q --> L

```

### 💾 Sistema de Persistencia

```

// Archivo: scoreboard.txt (mismo directorio que el ejecutable)
// Formato: nombre,movimientos

Julian,23
Maria,45
Pedro,67

```

**Hash Table Implementation:**
```

std::unordered_map<std::string, int> scores;
// Complejidad: O(1) para inserción/búsqueda
// Solo guarda el mejor score por jugador

```

---

## 🧪 Testing y Debug

### 🎁 Cheat Code

Presiona <kbd>G</kbd> durante el juego para activar el cheat:
- ✅ Agrega instantáneamente 10 tesoros
- ✅ Activa pantalla de victoria
- ✅ Prueba el sistema de scoreboard
- ⚠️ **Solo para propósitos de testing**
---

## 🎓 Conceptos Implementados

<div align="center">

| Concepto | Implementación | Archivo |
|:--------:|:--------------:|:-------:|
| **Lista Enlazada** | Tablero 9×9 con 4 conexiones | `Node.h/cpp` |
| **Pila (Stack)** | Inventario LIFO de tesoros | `Pila_tesoros.h/cpp` |
| **Hash Table** | Scoreboard con `unordered_map` | `Scoreboard.h/cpp` |
| **BFS** | Validación de conectividad | `Maze.cpp` |
| **Algoritmos de Ordenamiento** | Top 10 rankings | `Scoreboard.cpp` |
| **Persistencia** | Escritura/lectura de archivos | `Scoreboard.cpp` |
| **Manejo de Memoria** | Punteros y destructores | `Game.cpp` |

</div>

---

## 📸 Screenshots

<details>
<summary><b>🖼️ Ver Capturas de Pantalla</b></summary>


### Pantalla de Inicio
![Pantalla de Inicio](https://i.imgur.com/8I6V7gH.png)

### Pantalla de Victoria
![Pantalla de Victoria](https://i.imgur.com/kKSmoy4.png)


### Tabla de Puntuaciones
![Tabla de Puntuaciones](https://i.imgur.com/kiZ3VNj.png)
</details>

---

## 🤝 Contribuciones

Este proyecto fue desarrollado como parte del curso **Estructuras de Datos 2025-2**.

### 🔧 Para Contribuir

1. Fork el proyecto
2. Crea una rama (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add: AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

---

## 👥 Equipo de Desarrollo

<div align="center">

| <img src="https://img.icons8.com/color/96/000000/user-male-circle--v1.png"/> | <img src="https://img.icons8.com/color/96/000000/user-male-circle--v1.png"/> | <img src="https://img.icons8.com/color/96/000000/user-male-circle--v1.png"/> |
|:---:|:---:|:---:|
| **DavidVal2** | **josedav1102** | **julianandresdev** |
| Estructuras Base | Integración & Testing | Game Logic & Persistencia |

</div>

---

## 📜 Licencia

Este proyecto es académico y fue desarrollado para fines educativos.

```

Copyright © 2025 - Estructuras de Datos 2025-2
Todos los derechos reservados.

```

---

## 🙏 Agradecimientos

- 🎓 Profesor Gonzo
- 📚 Comunidad de C++ en Stack Overflow (y google)
- 🤖 Claude Sonnet 4.5 ♥️

---

<div align="center">

### 🌟 Si te gustó el proyecto, considera darle una ⭐

**[⬆ Volver al inicio](#-laberinto-dinámico---juego-de-aventuras-en-c)**

---

**Hecho con ❤️ y C++ en 2025**

[![GitHub](https://img.shields.io/badge/GitHub-josedav1102%2Fproyecto--c---181717?style=for-the-badge&logo=github)](https://github.com/josedav1102/proyecto-c--)

</div>


***

