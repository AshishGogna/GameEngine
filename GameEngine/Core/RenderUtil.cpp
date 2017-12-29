//
//  RenderUtil.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "RenderUtil.hpp"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>

void RenderUtil::ClearScreen()
{
    //TODO: Stencil buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderUtil::InitGraphics()
{
    glClearColor(0, 0, 0, 0);
    
    //Draw what faces the camera
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    
    glEnable(GL_DEPTH_TEST);
    //TODO: Depth clamp
    
    glEnable(GL_FRAMEBUFFER_SRGB);
}
