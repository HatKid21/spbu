add_library(entities_base STATIC)

target_sources(entities_base
    PRIVATE
        gameObject.cpp
        movable.cpp
    PUBLIC
        gameObject.hpp
        movable.hpp
        objectTypes.hpp
)
target_include_directories(
    entities_base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(entities_base PUBLIC game_utils)
