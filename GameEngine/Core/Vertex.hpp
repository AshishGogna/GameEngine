//
//  Vertex.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include "Vector3.hpp"
#include "Vector2.hpp"
class Vertex
{
private:
    void Init(Vector3 position, Vector2 texCoord);

public:
    static const int SIZE = 5;
    Vector3 position;
    Vector2 texCoord;
    
    Vertex(Vector3 position);
    Vertex(Vector3 position, Vector2 texCoord);
};

#endif /* Vertex_hpp */
