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

class Window
{
private:
    int width;
    int height;
    const char *title;
    GLFWwindow *window;
    void Init(int w, int h, const char *t);
    
public:
    Window();
    Window(int w, int h, const char *t);

    bool isCloseRequested();
    void Update();
    void Terminate();

    int tWidth();
    int tHeight();
    const char *tTitle();
};
