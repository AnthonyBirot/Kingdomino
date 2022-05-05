cmake_minimum_required(VERSION 3.10)

# set the project name
project(kingdomino)

# add executables
add_executable(kingdomino
    src/main.cpp
    src/Game.cpp
    src/Domino.cpp
    src/Player.cpp
)

include_directories(include)