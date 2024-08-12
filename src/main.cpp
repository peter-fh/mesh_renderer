#include "window.h"
#include "shader.h"
#include "mesh.h"
#include "model.h"
#include "trivial_model.h"


#define HEIGHT 800
#define WIDTH 800


void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}


void testError(std::string message){
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR) {
		std::cerr << message << "\nError code:" << err << std::endl;
		exit(1);
	}
}
int main()
{

	GLFWwindow* window = init_window(HEIGHT, WIDTH, "MUG TIME");

	Shader shader("vertex.glsl", "fragment.glsl");
	Model model("./assets/bottle.obj");
	//Model model;
	//Mesh mesh;
	//std::cout << model;

	
	glViewport(0, 0, WIDTH, HEIGHT);
	testError("right after viewport");

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	testError("right after clear colors");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	testError("right after clear");
	glEnable(GL_DEPTH_TEST);
	glfwSwapBuffers(window); 
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		//Sets refresh rate to 60 fps
		glfwSwapInterval(1);

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();
		testError("error after using shader");
		model.draw();
		//mesh.draw();
		testError("error after drawing model");

		glfwSwapBuffers(window);

		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();

	return 1;
}
