#include <iostream>
#include "GLFW/glfw3.h"
#include "capi/litan_c_api.h"

extern "C" {
	void fenris_begin(ltn_CApi * api) {
		// std::cout << "fenris_begin" << std::endl;
		glBegin(GL_TRIANGLES);
	}



	void fenris_end(ltn_CApi * api) {
		// std::cout << "fenris_end" << std::endl;
		glEnd();
		glFlush();
	}



	void fenris_set_color(ltn_CApi * api) {
		// std::cout << "fenris_set_color" << std::endl;
		auto r = api->param_float(0, api->core);
		auto g = api->param_float(1, api->core);
		auto b = api->param_float(2, api->core);
		glColor3f(r, g, b);
	}



	void fenris_emit_vertex(ltn_CApi * api) {
		// std::cout << "fenris_emit_vertex" << std::endl;
		auto x = api->param_float(0, api->core);
		auto y = api->param_float(1, api->core);
		glVertex2f(x, y);
	}
}