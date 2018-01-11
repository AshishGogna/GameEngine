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
    glGenBuffers(1, &ibo);

    size = 0;
}

void Mesh::AddVertices(vector<Vertex> vertices, vector<int> indices)
{
    size = (int)indices.size();
    int vertsSize = (int)vertices.size() * Vertex::SIZE;

    //Convert buffer from vertices vector
    GLfloat verts[vertsSize];
    int i=0;
    for (int j=0; j<(int)vertices.size(); j++)
    {
        verts[i] = vertices[j].position.x;
        i++;
        verts[i] = vertices[j].position.y;
        i++;
        verts[i] = vertices[j].position.z;
        i++;
        verts[i] = vertices[j].texCoord.x;
        i++;
        verts[i] = vertices[j].texCoord.y;
        i++;
    }

    //Convert buffer from indices vector
    GLuint inds[size];
    for (int j=0; j<size; j++)
    {
        inds[j] = indices[j];
    }
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(inds), inds, GL_STATIC_DRAW);
}

void Mesh::Draw()
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(
                          0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          Vertex::SIZE * 4,
                          (void*)0
                          );
    glVertexAttribPointer(
                          1,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          Vertex::SIZE * 4,
                          (void*)12
                          );

    //glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
