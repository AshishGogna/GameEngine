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
}

void Mesh::AddVertices(vector<Vertex> vertices)
{
    if (!Window::isInitialized()) return;

    /*
    size = (int)vertices.size();// * Vertex::SIZE;
    
    Vertex* verts = &vertices[0];

    glBindBuffer(GL_ARRAY_BUFFER, vbo); //Makes all buffer operations affect vbo
    glBufferData(GL_ARRAY_BUFFER, size, verts, GL_STATIC_DRAW);
    */

    GLuint VertexArrayID;
    glGenVertexArraysAPPLE(1, &VertexArrayID);
    glBindVertexArrayAPPLE(VertexArrayID);

    
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

    //GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vbo);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

void Mesh::Draw()
{
    /*
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex::SIZE*4, 0);
    
    glDrawArrays(GL_TRIANGLES, 0, size);

    glDisableVertexAttribArray(0);
    */
    
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
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}
