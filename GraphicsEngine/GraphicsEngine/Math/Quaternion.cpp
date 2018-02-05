//
//  Quaternion.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 05/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Quaternion.hpp"
#include <math.h>

Quaternion::Quaternion()
{
    
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float Quaternion::Length()
{
    return sqrtf(x*x + y*y + z*z + w*w);
}

Quaternion Quaternion::Normalize()
{
    float length = Length();
    
    x /= length;
    y /= length;
    z /= length;
    w /= length;
    
    return *this;
}

Quaternion Quaternion::Conjugate()
{
    return Quaternion(-x, -y, -z, w);
}

Quaternion Quaternion::Multiply(Quaternion q)
{
    float _w = w*q.w - x*q.x - y*q.y - z*q.z;
    float _x = x*q.w + w*q.x + y*q.z - z*q.y;
    float _y = y*q.w + w*q.y + z*q.x - x*q.z;
    float _z = z*q.w + w*q.z + x*q.y - y*q.x;
    
    return  Quaternion(_x, _y, _z, _w);
}

Quaternion Quaternion::Multiply(Vector3 v)
{
    float _w = -x*v.x - y*v.y - z*v.z;
    float _x =  w*v.x + y*v.z - z*v.y;
    float _y =  w*v.y + z*v.x - x*v.z;
    float _z =  w*v.z + x*v.y - y*v.x;
    
    return Quaternion(_x, _y, _z, _w);
}
