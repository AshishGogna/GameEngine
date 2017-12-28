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
    if (!glfwInit()) exit(EXIT_FAILURE);
    window = glfwCreateWindow(w, h, t, NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
}

bool Window::isCloseRequested()
{
    return (glfwWindowShouldClose(window));
}

void Window::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::Dispose()
{
    glfwTerminate();
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
