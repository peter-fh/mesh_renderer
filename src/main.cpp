#include "window.h"
#include "shader.h"


//Window dimensions
#define HEIGHT 800
#define WIDTH 800


//Function for closing the window when the escape key is pressed
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}


int main()
{

	GLFWwindow* window = init_window(HEIGHT, WIDTH, "the mug");

	//Vertices of the (equilateral) triangle
	Shader shader("vertex.glsl", "fragment.glsl");
	
	GLfloat vertices[]{
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};


	//Vertex array object and vertex buffer object:
	//VBO stores vertex data
	//VAO stores pointers to VBO data and tells OpenGL how to interpret them
	GLuint VAO, VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO); //1 represents the number of objects stored by the VBO

	//Binding is sort of like making this a global variable that will be modified whenever functions are called on that particular buffer (I think)
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Storing vertex data in the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//Defining viewport
	glViewport(0, 0, WIDTH, HEIGHT);

	//Changing the background colour
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window); //Important to swap buffers after a change so the window actually updates



	//Main render loop
	while (!glfwWindowShouldClose(window)) {
		//Processing input (just for the escape key, all the other inputs are just handled in this loop)
		processInput(window);

		//Sets refresh rate to 60 fps
		glfwSwapInterval(1);

		//Refreshing background colour
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();

		//Draw the triangle
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//Swap front and back buffer
		glfwSwapBuffers(window);

		//Handles events
		glfwPollEvents();
	}

	//Cleanup
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	//Kill the window
	glfwDestroyWindow(window);

	//End glfw
	glfwTerminate();
	return 1;
}
