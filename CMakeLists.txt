cmake_minimum_required(VERSION 3.10)
project(JuegoLaberinto)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(laberinto
        src/main.cpp
        src/Node.cpp
        src/Maze.cpp
        src/Player.cpp
        src/Treasure.cpp
        src/Scoreboard.cpp
        src/Game.cpp
        include/Maze.h
        include/Player.h
        include/Scoreboard.h
        include/Treasure.h
        include/Game.h
        include/Pila_tesoros.h
        src/Pila_tesoros.cpp
        include/Utilities.h
        include/Constants.h
)
