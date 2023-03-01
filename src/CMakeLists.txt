cmake_minimum_required(VERSION 3.13)

add_library(fenrir SHARED
	main.cxx
	vertex.cxx
	window.cxx
)

target_link_libraries(fenrir glfw GL)
