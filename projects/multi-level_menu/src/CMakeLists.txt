target_sources(multi-level_menu_lib
	PRIVATE
		menuItems.cpp
		menuFunctions.cpp
	PUBLIC
		menuItems.hpp
		menuFunctions.hpp
		menu.hpp
		artAssets.hpp
)

target_include_directories(multi-level_menu_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
