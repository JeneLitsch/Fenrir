cmake_minimum_required(VERSION 3.13)
project(TPITS)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

include_directories(
	./
	./libs/
	./libs/glfw/include
	./src
)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/glfw)
add_subdirectory(src)

# target_link_libraries(ltnsfml
# 	pthread
# )

