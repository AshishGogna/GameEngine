//
//  main.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 26/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>

int main(int argc, const char * argv[]) {

    //Test code
    GLFWwindow *window;
    if (!glfwInit()) exit(EXIT_FAILURE);
    window = glfwCreateWindow(1024, 768, "glfw", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    return 0;
}
