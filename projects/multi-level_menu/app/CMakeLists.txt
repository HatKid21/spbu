set(SOURCES
	main.cpp
)

add_executable(app ${SOURCES})

target_link_libraries(app
	multi-level_menu_lib
)
