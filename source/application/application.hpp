#pragma once

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Application {

    public:

        Application();
        ~Application();

        void resize_window(unsigned int x, unsigned int y);
        void retitle_window(std::string title);

        GLFWwindow* get_window_ptr() { return window_ptr; }

    private:

        GLFWwindow* window_ptr = nullptr;

        unsigned int width, height;
        std::string title;

        static void FramebufferSizeCallback(GLFWwindow* window, int w, int h);

}; // Application