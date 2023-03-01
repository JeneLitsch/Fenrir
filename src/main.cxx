#include <iostream>
#include "GLFW/glfw3.h"
#include "capi/litan_c_api.h"

extern "C" {
	void fenris_init(ltn_CApi * api) {
		// std::cout << "fenris_init" << std::endl;
		glfwInit();
	}
}