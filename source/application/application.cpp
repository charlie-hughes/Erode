#include "application.hpp"

#include <iostream>


// Application constructor
Application::Application() {
    if (!glfwInit()) {
        std::cout << "Could not init GLFW!\n";
        return;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // use forward compatability if using apple
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif


    Application::width = 1280;
    Application::height = 720;
    Application::title = "Erode";

    Application::window_ptr = glfwCreateWindow(Application::width, Application::height, Application::title.c_str(), NULL, NULL);

    if (!Application::window_ptr) {
        std::cout << "Could not create window!\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(Application::window_ptr);

    gladLoadGL();

    int framebuffer_width;
    int framebuffer_height;

    glfwGetFramebufferSize(Application::window_ptr, &framebuffer_width, &framebuffer_height);
    glViewport(0, 0, framebuffer_width, framebuffer_height);

    glfwSetFramebufferSizeCallback(Application::window_ptr, FramebufferSizeCallback);
}

// Application destructor
Application::~Application() {
    glfwDestroyWindow(Application::window_ptr);

    glfwTerminate();
}

// ===== Application Functions ===== //

void Application::resize_window(unsigned int x, unsigned int y) {
    Application::width = x;
    Application::height = y;

    glfwSetWindowSize(Application::window_ptr, x, y);
}

void Application::retitle_window(std::string t) {
    Application::title = t;

    glfwSetWindowTitle(Application::window_ptr, t.c_str());
}

// ===== Application Callbacks ===== //

void Application::FramebufferSizeCallback(GLFWwindow* window, int w, int h) {
    glViewport(0, 0, w, h);
}