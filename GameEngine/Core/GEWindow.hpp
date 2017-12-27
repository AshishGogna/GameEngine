//
//  GEWindow.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef GEWindow_hpp
#define GEWindow_hpp

#include <stdio.h>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>

#endif /* GEWindow_hpp */

class GEWindow
{
private:
    int width;
    int height;
    const char *title;
    GLFWwindow *window;
    void Init(int w, int h, const char *t);
    
public:
    GEWindow();
    GEWindow(int w, int h, const char *t);

    bool isCloseRequested();
    void Update();
    void Terminate();

    int GetWidth();
    int GetHeight();
    const char *GetTitle();
};
