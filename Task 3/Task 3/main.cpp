// Include necessary build libraries
#pragma comment(lib, "glfw3dll")
#pragma comment(lib, "OpenGL32")

// States that we are using the DLL for GLFW
#define GLFW_DLL

// Include files
#include <GLFW\glfw3.h>
#include <chrono>

using namespace std::chrono;

// Window opened via GLFW
GLFWwindow* window;

// Flag used to monitor state of application
bool running = true;

// Initialises the application
bool initialise()
{
	// Set clear colour to cyan
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	// Enable face culling
	glEnable(GL_CULL_FACE);
	return true;
}

// Updates the application
void update(double deltaTime)
{
	// Check if escape pressed or window is closed
	running = !glfwGetKey(window, GLFW_KEY_ESCAPE) && !glfwWindowShouldClose(window);
}

// Renders the application
void render()
{
	// Clear the scene
	glClear(GL_COLOR_BUFFER_BIT);
	// Set the colour
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	//// Render a triangle
	//glBegin(GL_TRIANGLES);
	//	// Triangle 1
	//	glVertex3f(-0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, 0.5f, 0.0f);
	//	// Triangle 2
	//	glVertex3f(0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, -0.5f, 0.0f);
	//glEnd();
	// Render a quad
	//glBegin(GL_QUADS);
	//	// Quad has 4 vertexes (corners)
	//	glVertex3f(0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, -0.5f, 0.0f);
	//glEnd();
	// Render a quad
	//glBegin(GL_TRIANGLE_STRIP);
	//	glVertex3f(0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, 0.5f, 0.0f); // This gives the quad it's shape
	//glEnd();
	//// Render a quad
	//glBegin(GL_LINES);
	//	// Line 1
	//	glVertex3f(0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, 0.5f, 0.0f);
	//	// Line 2
	//	glVertex3f(-0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, -0.5f, 0.0f);
	//	// Line 3
	//	glVertex3f(-0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, -0.5f, 0.0f);
	//	// Line 4
	//	glVertex3f(0.5f, -0.5f, 0.0f);
	//	glVertex3f(0.5f, 0.5f, 0.0f);
	//glEnd();
	// Render a quad
	glBegin(GL_LINE_STRIP);
		glVertex3f(0.5f, 0.5f, 0.0f);
		glVertex3f(-0.5f, 0.5f, 0.0f);
		glVertex3f(-0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, -0.5f, 0.0f);
		glVertex3f(0.5f, 0.5f, 0.0f);
	glEnd();
	//// Render a quad
	//glBegin(GL_TRIANGLE_FAN);
	//	glVertex3f(0.0f, 0.0f, 0.0f);
	//	glVertex3f(0.0f, 0.5f, 0.0f);
	//	glVertex3f(0.5f, 0.5f, 0.0f);

	//	glVertex3f(0.0f, 0.0f, 0.0f);
	//	glVertex3f(0.5f, 0.5f, 0.0f);
	//	glVertex3f(-0.5f, -0.5f, 0.0f);
	//glEnd();
	// Swap front and back buffers
	glfwSwapBuffers(window);
}

// Main Operation
int main()
{
	// Try and initialise GLFW
	if (!glfwInit())
		return -1;

	// Create a window for OpenGL rendering
	window = (glfwCreateWindow(800, 600, "Hello World", nullptr, nullptr));
	// Check if window was created
	if (window == nullptr)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	// Initialise the application
	if (!initialise())
	{
		glfwTerminate();
		return -1;
	}

	// Monitor the elapsed time per frame
	auto currentTimeStamp = system_clock::now();
	auto prevTimeStamp = system_clock::now();

	// Loop until running set to false
	while (running)
	{
		// Get current time
		currentTimeStamp = system_clock::now();
		// Calculate elapsed time
		auto elapsed = duration_cast<milliseconds>(currentTimeStamp - prevTimeStamp);
		// Convert to fractions of a second
		auto seconds = double(elapsed.count()) / 1000.0;

		// Update application
		update (seconds);
		// Render scene
		render();
		//Poll for and process events
		glfwPollEvents();
		// Set previous time stamp to current time stamp
		prevTimeStamp = currentTimeStamp;
	}

	// Terminate GLFW
	glfwTerminate();

	return -1;
}