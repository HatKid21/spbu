cmake_minimum_required(VERSION 3.2...3.27.5)

project(super_mario)

find_package(Curses REQUIRED)

add_subdirectory(utils)
add_subdirectory(entities)
add_subdirectory(game)

add_executable(out main.cpp)

target_link_libraries(out
    PRIVATE 
        game_engine
        ${CURSES_LIBRARIES}
)

target_include_directories(out PRIVATE ${CURSES_INCLUDE_DIRS})
