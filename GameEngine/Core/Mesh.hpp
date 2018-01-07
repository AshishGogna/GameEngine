//
//  Mesh.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/OpenGL.h>
#include "Vertex.hpp"
#include <vector>

#endif /* Mesh_hpp */

class Mesh
{
private:
    GLuint vbo;
    GLuint ibo; //index buffer object
    int size;
    vector<int> a;
    GLuint programID;
    
    GLfloat* CreateBuffer(vector<Vertex> vertices);
    
public:
    Mesh();
    
    void AddVertices(vector<Vertex> vertices, vector<int> indices);
    void Draw();
};
