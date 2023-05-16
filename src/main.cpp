#include <stdio.h>
#include <cstdlib>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

const char* WINDOW_TITLE = "HELLO_WORLD";
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
const glm::vec4 BG_COLOR = { 0.3f,0.7f,0.9f,1.0f };

int main(){
	if (!glfwInit()) {
		printf("GLFW failed to initialize");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT,WINDOW_TITLE, NULL,NULL);
	if (!window) {
		printf("GLFW failed to create window");
		return 1;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL();

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, BG_COLOR.a);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}