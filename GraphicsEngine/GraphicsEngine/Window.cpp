//
//  Window.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Window.hpp"
#include "Util.hpp"

int Window::width;
int Window::height;
string Window::name;
GLFWwindow* Window::window;

void Window::CreateWindow(int w, int h, string n)
{
    width = w;
    height = h;
    name = n;
    
    if(!glfwInit())
    {
        Util::ExitWithError("Failed to initialize GLFW");
    }
    glfwWindowHint(GLFW_SAMPLES, 4);                               // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                 // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    
    window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if(window == NULL)
    {
        glfwTerminate();
        Util::ExitWithError("Failed to open GLFW window");
    }
    glfwMakeContextCurrent(window);
    
    glewExperimental=true;
    if (glewInit() != GLEW_OK)
    {
        Util::ExitWithError("Failed to initialize GLEW");
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    InitGraphics();
}

void Window::Terminate()
{
    glfwTerminate();
}

void Window::Clear()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::SwapBuffers()
{
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Window::ShouldClose()
{
    return (glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

GLFWwindow* Window::GetWindow()
{
    return window;
}

bool Window::isInitialized()
{
    return (window != NULL);
}

void Window::InitGraphics()
{
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    //Draw what faces the camera
    //glFrontFace(GL_CW);
    //glCullFace(GL_BACK);
    //glEnable(GL_CULL_FACE);
    //glEnable(GL_DEPTH_TEST);
    
    //glEnable(GL_DEPTH_CLAMP);
    //glEnable(GL_TEXTURE_2D);
    
    //glEnable(GL_FRAMEBUFFER_SRGB);
}
