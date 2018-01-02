//
//  Window.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Window.hpp"

int Window::width;
int Window::height;
string Window::title;
GLFWwindow* Window::window;

void Window::CreateWindow(int w, int h, const char *t)
{
    //glfwCreateWindow(640, 480, "Hello World", NULL, NULL );

    if (!glfwInit()) exit(EXIT_FAILURE);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(w, h, t, NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    glewExperimental = true;
    
    if(glewInit() != GLEW_OK) {
        cout << "Failed to initialize GLEW... exiting" << endl;
        exit(EXIT_FAILURE);
    }
    
}

bool Window::isCloseRequested()
{
    return (glfwWindowShouldClose(window));
}

void Window::Render()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::Dispose()
{
    glfwTerminate();
}

bool Window::isInitialized()
{
    return (window != NULL); //temp sol, i guess...
}

int Window::getWidth()
{
    return width;
}

int Window::getHeight()
{
    return height;
}

string Window::getTitle()
{
    return title;
}
