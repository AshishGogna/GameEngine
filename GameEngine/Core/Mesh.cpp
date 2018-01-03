//
//  Mesh.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Mesh.hpp"
#include <GL/glew.h>
#include "Window.hpp"

Mesh::Mesh()
{
    if (!Window::isInitialized()) return;
    
    glGenBuffers(1, &vbo);
    size = 0;
}

void Mesh::AddVertices(vector<Vertex> vertices)
{
    size = (int)vertices.size();
    int vertsSize = (int)vertices.size() * Vertex::SIZE;

    //Convert buffer (GLfloat array) from vector
    GLfloat verts[vertsSize];
    int i=0;
    while (i<vertsSize)
    {
        for (int j=0; j<size; j++)
        {
            verts[i] = vertices[j].position.x;
            i++;
            verts[i] = vertices[j].position.y;
            i++;
            verts[i] = vertices[j].position.z;
            i++;
        }
    }

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
}

void Mesh::Draw()
{
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(
                          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                          3,                  // size
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
}
