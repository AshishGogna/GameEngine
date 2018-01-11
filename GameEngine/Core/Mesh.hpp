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

class Mesh
{
private:
    GLuint vbo;
    GLuint ibo; //index buffer object
    int size;
    vector<int> a;
    GLuint programID;
    
    GLfloat* CreateBuffer(vector<Vertex> vertices);
    void CalculateNormals(vector<Vertex> &vertices, vector<int> &indices);
    
public:
    Mesh();
    
    void AddVertices(vector<Vertex> vertices, vector<int> indices);
    void AddVertices(vector<Vertex> vertices, vector<int> indices, bool calculateNormals);
    void Draw();
};

#endif /* Mesh_hpp */
