cmake_minimum_required(VERSION 3.20)
project(LifeGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets CONFIG REQUIRED)

set(src main.cpp main_window.cpp)

add_executable(LifeGame ${src})
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
