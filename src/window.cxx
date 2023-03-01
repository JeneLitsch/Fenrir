#include <iostream>
#include "GLFW/glfw3.h"
#include "capi/litan_c_api.h"

extern "C" {

	void fenris_window_create(ltn_CApi * api) {
		// std::cout << "fenris_window_create" << std::endl;
		auto width = api->param_int(0, api->core);	
		auto height = api->param_int(1, api->core);	
		auto title = api->param_string(2, api->core);	
		auto window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		glfwMakeContextCurrent(window);
		api->return_object(ltn_CObject{
			.ptr = window,
		}, api->core);
	}



	void fenris_window_close(ltn_CApi * api) {
		// std::cout << "fenris_window_close" << std::endl;
		auto window = api->param_object(0, api->core);
		glfwDestroyWindow(reinterpret_cast<GLFWwindow*>(window.ptr));
	}



	void fenris_window_is_open(ltn_CApi * api) {
		// std::cout << "fenris_window_is_open" << std::endl;
		auto window = api->param_object(0, api->core);
		auto is_open = !glfwWindowShouldClose(reinterpret_cast<GLFWwindow*>(window.ptr));
		api->return_bool(is_open, api->core);
	}



	void fenris_window_poll_events(ltn_CApi * api) {
		// std::cout << "fenris_window_poll_events" << std::endl;
		auto window = api->param_object(0, api->core);
		glfwMakeContextCurrent(reinterpret_cast<GLFWwindow*>(window.ptr));
		glfwPollEvents();
	}






	void fenris_window_clear(ltn_CApi * api) {
		// std::cout << "fenris_window_clear_color" << std::endl;
		auto window = api->param_object(0, api->core);
		auto r = api->param_int(1, api->core);
		auto g = api->param_int(2, api->core);
		auto b = api->param_int(3, api->core);
		glfwMakeContextCurrent(reinterpret_cast<GLFWwindow*>(window.ptr));
		glClearColor(r / 255.f, g / 255.f, b / 255.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
	}



	void fenris_window_display(ltn_CApi * api) {
		// std::cout << "fenris_window_display" << std::endl;
		auto window = api->param_object(0, api->core);
		glfwSwapBuffers(reinterpret_cast<GLFWwindow*>(window.ptr));
	}
}