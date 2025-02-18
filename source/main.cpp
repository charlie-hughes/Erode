#include <iostream>

#include "application/application.hpp"

int main(const int argc, const char* argv[]) {

    Application app = Application();
    
    // Simulator.create()
    // Set parameters
    // Simulator.run()

    while (!glfwWindowShouldClose(app.get_window_ptr()))
    {
        glfwSwapBuffers(app.get_window_ptr());

        glfwPollEvents();
    }
    

    app.~Application();

}