//
//  Mesh.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Mesh.hpp"
#include <GL/glew.h>

Mesh::Mesh()
{
    //cout << "bb" << endl;
    vbo = 0;
    //glGenBuffers(1, &vbo);
    
    size = 0;
}

void Mesh::AddVertices(vector<Vertex> vertices)
{
    size = (int)vertices.size();// * Vertex::SIZE;
    
    Vertex* verts = &vertices[0];

    //Makes all buffer operations affect vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, verts, GL_STATIC_DRAW);
}

void Mesh::Draw()
{
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex::SIZE*4, 0);
    
    glDrawArrays(GL_TRIANGLES, 0, size);

    glDisableVertexAttribArray(0);
}
