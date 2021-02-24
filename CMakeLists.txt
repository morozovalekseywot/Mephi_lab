set(CMAKE_C_COMPILER "C:/minigw64/mingw64/bin/cmd.exe")
cmake_minimum_required(VERSION 3.17)

project(Vertex)

include_directories(include)
set(CMAKE_C_STANDARD 99)
set(HEADERS
        include/Vector3d.h)

set(SOURCES
        Sources/Vector3d.c
        Sources/main.c)

add_executable(${CMAKE_PROJECT_NAME} ${HEADERS} ${SOURCES})
#add_library(include/Vector3d.h Sources/Vector3d.c)