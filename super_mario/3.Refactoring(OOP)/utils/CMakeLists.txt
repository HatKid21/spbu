add_library(game_utils STATIC)

target_sources(game_utils
    PRIVATE
        keyboard.cpp
        physics.cpp
        renderer.cpp
    PUBLIC
        keyboard.hpp
        physics.hpp
        renderer.hpp
)

target_include_directories(game_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(game_utils PUBLIC game_engine entities_base)
