set(SOURCES
	sort_test.cpp
)

add_executable(test_merge ${SOURCES})

target_link_libraries(test_merge
	sort_lib
	gtest_main
	gmock_main
)

add_test(sort_test test_merge)
