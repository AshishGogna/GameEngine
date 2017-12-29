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

#endif /* Vertex_hpp */

class Vertex
{
public:
    static const int SIZE = 3;
    Vector3 position;
    
    Vertex(Vector3 position);
};
