#include "window.h"
#include "shader.h"
#include "model.h"
#include "transform.h"


#define HEIGHT 800
#define WIDTH 800

#define BACKGROUND_COLOR 0.168f, 0.168f, 0.168f, 1.0f
#define OBJECT_COLOR 0.0f, 1.0f, 0.8f, 1.0f

Transform transform;


bool fill_mode = false;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		if (fill_mode) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			fill_mode = false;
		} else {
			fill_mode = true;
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
	}
}


bool first_mouse = true;
double lastX;
double lastY;
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
		transform.translate(0, 1, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
		transform.translate(0, -1, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
		transform.translate(-1, 0, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
		transform.translate(1, 0, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
		transform.rotate(0, -1, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
		transform.rotate(0, 1, 0);
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS){
		transform.scale(1);
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS){
		transform.scale(-1);
	}
}

void mouse_callback(GLFWwindow*, double xpos, double ypos){
	if (first_mouse){
		lastX = xpos;
		lastY = ypos;
		first_mouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = ypos - lastY;
	lastX = xpos;
	lastY = ypos;

	transform.rotate(-glm::radians(yoffset), 0, glm::radians(xoffset));
}

int main() {

	GLFWwindow* window = init_window(HEIGHT, WIDTH, "MUG TIME");
	Shader shader("vertex.glsl", "fragment.glsl");
	Model model("bottle.obj");

#ifdef __APPLE__
	glViewport(0, 0, WIDTH * 2, HEIGHT * 2);
#else
	glViewport(0, 0, WIDTH, HEIGHT);
#endif

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  
	glfwSetCursorPosCallback(window, mouse_callback);  
	glfwSetKeyCallback(window, key_callback);

	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window)) {

		processInput(window);

		glClearColor(BACKGROUND_COLOR);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();

		glm::mat4 transformation = transform.matrix();
		shader.setm4f("transform", transformation);

		glm::vec4 color = glm::vec4(OBJECT_COLOR);
		shader.set4f("color", color);

		model.draw();


		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 1;
}
