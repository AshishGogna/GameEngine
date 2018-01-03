//
//  Window.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>

#endif /* Window_hpp */

using namespace std;

class Window
{
private:
    static int width;
    static int height;
    static string title;

public:
    static GLFWwindow* window;

    static void CreateWindow(int w, int h, const char *t);

    static bool isCloseRequested();
    static void SwapBuffers();
    static void Dispose();
    static bool isInitialized();

    int getWidth();
    int getHeight();
    string getTitle();
};
