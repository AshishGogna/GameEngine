//
//  Mesh.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <iostream>
#include "Vertex.hpp"
#include <vector>
#include "Transform.hpp"

using namespace std;

class Mesh
{
private:
    GLuint vbo;
    GLuint ibo;
    
    void  Init();
    void AddVertices(vector<Vertex> vertices, vector<int> indices);
    
public:
    int size;
    Transform transform;
    
    Mesh();
    Mesh(vector<Vertex> vertices, vector<int> indices);
    
    void Draw();
};

#endif /* Mesh_hpp */
