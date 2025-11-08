cmake_minimum_required(VERSION 3.10)

# Nombre de tu proyecto
project(proyecto-c)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir el directorio de headers
include_directories(include)

# Recopilar todos los archivos fuente
file(GLOB SOURCES
        src/*.cpp
)

# Recopilar todos los archivos header (opcional, para visualización)
file(GLOB HEADERS
        include/*.h
)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Si necesitas agregar el directorio de data
# add_definitions(-DDATA_DIR="${CMAKE_SOURCE_DIR}/data/")
