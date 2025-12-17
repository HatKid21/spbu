target_sources(${LIBRARY}
	PRIVATE
		io.cpp
		sortings.cpp
	PUBLIC
		io.hpp
		sortings.hpp
)

target_include_directories(${LIBRARY} PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
