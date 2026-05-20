add_library(entities_enemy STATIC)

target_sources(entities_enemy
    PRIVATE
        enemy.cpp
    PUBLIC
        enemy.hpp
)

target_include_directories(entities_enemy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(entities_enemy PUBLIC entities_base)
