//
//  Vector2.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Vector2_hpp
#define Vector2_hpp

#include <stdio.h>
#include <iostream>

#endif /* Vector2_hpp */

using namespace std;

class Vector2
{
    
public:
    float x, y;

    Vector2(float x, float y);
    
    float Length();
    float Dot(Vector2);
    Vector2 Normalize();
    Vector2 Rotate(float angle);
    
    Vector2 Add(Vector2 v);
    Vector2 Add(float f);
    
    Vector2 Subtract(Vector2 v);
    Vector2 Subtract(float f);

    Vector2 Multiply(Vector2 v);
    Vector2 Multiply(float f);

    Vector2 Divide(Vector2 v);
    Vector2 Divide(float f);
    
    string ToString();
};
