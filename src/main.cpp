#include "Window.hpp"
#include <iostream>

int main () {
    Window window;
    if (window.init() == -1) {
        std::cerr << "Error happened when launching a program\n";
        return -1;
    }
    while (glfwWindowShouldClose(window.getWindow()) == false) {
        window.inputproc();
        window.draw();
        glfwPollEvents();
    }
    glfwTerminate();
}