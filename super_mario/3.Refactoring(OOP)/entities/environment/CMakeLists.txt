add_library(entities_environment STATIC)

target_sources(entities_environment
    PRIVATE
        brick.cpp
        coin.cpp
    PUBLIC
        brick.hpp
        coin.hpp
)

target_include_directories(
    entities_environment PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(entities_environment PUBLIC entities_base)
