target_sources(${CONTAINERS_LIB}
    PRIVATE
        #doubly_linked_list.cpp
        vector.cpp
    PUBLIC
        vector.hpp
)

target_include_directories(${CONTAINERS_LIB} PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)
