//
//  GEWindow.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "GEWindow.hpp"

GEWindow::GEWindow()
{
    Init(800, 600, "A Window");
}

GEWindow::GEWindow(int w, int h, const char *t)
{
    Init(w, h, t);
}

void GEWindow::Init(int w, int h, const char *t)
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

bool GEWindow::isCloseRequested()
{
    return (glfwWindowShouldClose(window));
}

void GEWindow::Update()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void GEWindow::Terminate()
{
    glfwTerminate();
}

int GEWindow::GetWidth()
{
    return width;
}

int GEWindow::GetHeight()
{
    return height;
}

const char *GEWindow::GetTitle()
{
    return title;
}
