add_library(entities_player STATIC)

target_sources(entities_player
    PRIVATE
        player.cpp
    PUBLIC
        player.hpp
)

target_include_directories(entities_player PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entities_player PUBLIC entities_base game_engine)
