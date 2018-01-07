//
//  Window.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Window.hpp"
#include "Util.hpp"

int Window::width;
int Window::height;
string Window::title;
GLFWwindow* Window::window;

void Window::CreateWindow(int w, int h, const char *t)
{
    if( !glfwInit() )
    {
        Util::Print("Failed to initialize GLFW");
        Util::Exit();
    }

    glfwWindowHint(GLFW_SAMPLES, 4); //4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( w, h, t, NULL, NULL);
    if( window == NULL )
    {
        Util::Print("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version.");
        glfwTerminate();
        Util::Exit();
    }
    glfwMakeContextCurrent(window); //Initialize GLEW
    glewExperimental=true; //Needed in core profile
    if (glewInit() != GLEW_OK)
    {
        Util::Print("Failed to initialize GLEW");
        Util::Exit();
    }

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    width = w;
    height = h;
    title = t;
}

bool Window::isCloseRequested()
{
    return (glfwWindowShouldClose(window));
}

void Window::SwapBuffers()
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
