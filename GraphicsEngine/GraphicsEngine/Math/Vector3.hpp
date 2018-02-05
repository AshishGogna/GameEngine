//
//  Vector3.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Vector3_hpp
#define Vector3_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Vector3
{
public:
    float x, y, z;
    Vector3();
    Vector3(float x, float y, float z);
    
    float Length();
    float Dot(Vector3 v);
    Vector3 Cross(Vector3 v);
    Vector3 Normalized();
    Vector3 Add(Vector3 v);
    Vector3 Add(float v);
    Vector3 Subtract(Vector3 v);
    Vector3 Subtract(float f);
    Vector3 Multiply(Vector3 v);
    Vector3 Multiply(float f);
    Vector3 Divide(Vector3 v);
    Vector3 Divide(float f);
    Vector3 Abs();
    Vector3 Zero();
    Vector3 One();
    string ToString();
};

#endif /* Vector3_hpp */
