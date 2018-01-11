//
//  Vertex.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Vertex.hpp"

Vertex::Vertex(Vector3 position)
{
    Init(position, Vector2(0, 0));
}

Vertex::Vertex(Vector3 position, Vector2 texCoord)
{
    Init(position, texCoord);
}

void Vertex::Init(Vector3 position, Vector2 texCoord)
{
    this->position = position;
    this->texCoord = texCoord;
}
