//
//  Window.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Window.hpp"

Window::Window()
{
    Init(800, 600, "A Window");
}

Window::Window(int w, int h, const char *t)
{
    Init(w, h, t);
}

void Window::Init(int w, int h, const char *t)
{
    //Test code
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

void Window::Update()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::Terminate()
{
    glfwTerminate();
}

int Window::tWidth()
{
    return width;
}

int Window::tHeight()
{
    return height;
}

const char *Window::tTitle()
{
    return title;
}
