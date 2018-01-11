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
    AddVertices(vertices, indices, false);
}

void Mesh::AddVertices(vector<Vertex> vertices, vector<int> indices, bool calculateNormals)
{
    if (calculateNormals)
        CalculateNormals(vertices, indices);

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
        verts[i] = vertices[j].normal.x;
        i++;
        verts[i] = vertices[j].normal.y;
        i++;
        verts[i] = vertices[j].normal.z;
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
    glEnableVertexAttribArray(2);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex::SIZE * 4, (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, Vertex::SIZE * 4, (void*)12);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, Vertex::SIZE * 4, (void*)20);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
    
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
}

void Mesh::CalculateNormals(vector<Vertex> &vertices, vector<int> &indices)
{
    for (int i=0; i<indices.size(); i+=3)
    {
        int i0 = indices[i];
        int i1 = indices[i + 1];
        int i2 = indices[i + 2];
        
        Vector3 v1 = vertices[i1].position.Subtract(vertices[i0].position);
        Vector3 v2 = vertices[i2].position.Subtract(vertices[i0].position);
        
        Vector3 normal = v1.Cross(v2).Normalized();
        
        vertices[i0].normal = vertices[i0].normal.Add(normal);
        vertices[i1].normal = vertices[i1].normal.Add(normal);
        vertices[i2].normal = vertices[i2].normal.Add(normal);
    }
    
    for (int i=0; i<vertices.size(); i++)
    {
        vertices[i].normal = vertices[i].normal.Normalized();
    }
}
