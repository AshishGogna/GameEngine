//
//  Vertex.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include "Vector3.hpp"

class Vertex
{
private:
    
public:
    static const int SIZE = 3;
    Vector3 position;
    
    Vertex();
    Vertex(Vector3 pos);
};

#endif /* Vertex_hpp */
