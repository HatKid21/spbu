add_library(game_engine STATIC)

target_sources(game_engine
    PRIVATE
        game.cpp
        level.cpp
    PUBLIC
        game.hpp
        level.hpp
)

target_include_directories(game_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(game_engine
    PUBLIC
        game_utils
        entities_base
        entities_environment
        entities_enemy
        entities_player
)
