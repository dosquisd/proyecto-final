cmake_minimum_required(VERSION 3.24)
project(Proyecto_final)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto_final
        main.cpp
        empresa.h
        maquinaria.h
        operario.h
        equipo_mantenimiento.h
        fecha.h
        empresa.cpp
        equipo_mantenimiento.cpp
        fecha.cpp
        maquinaria.cpp
        operario.cpp)
