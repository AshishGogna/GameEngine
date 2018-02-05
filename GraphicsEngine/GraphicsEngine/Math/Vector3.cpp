//
//  Vector3.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Vector3.hpp"
#include <math.h>

Vector3::Vector3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3::Length()
{
    return sqrtf(x*x + y*y + z*z);
}

float Vector3::Dot(Vector3 v)
{
    return (x*v.x + y*v.y + z*v.z);
}

Vector3 Vector3::Cross(Vector3 v)
{
    float _x = y*v.z - z*v.y;
    float _y = z*v.x - x*v.z;
    float _z = x*v.y - y*v.x;
    
    return Vector3(_x, _y, _z);
}

Vector3 Vector3::Normalized()
{
    float length = Length();
    return Vector3(x/length, y/length, z/length);
}

Vector3 Vector3::Add(Vector3 v)
{
    return Vector3(x+v.x, y+v.y, z+v.z);
}

Vector3 Vector3::Add(float f)
{
    return Vector3(x+f, y+f, z+f);
}

Vector3 Vector3::Subtract(Vector3 v)
{
    return Vector3(x-v.x, y-v.y, z-v.z);
}

Vector3 Vector3::Subtract(float f)
{
    return Vector3(x-f, y-f, z-f);
}

Vector3 Vector3::Multiply(Vector3 v)
{
    return Vector3(x*v.x, y*v.y, z*v.z);
}

Vector3 Vector3::Multiply(float f)
{
    return Vector3(x*f, y*f, z*f);
}

Vector3 Vector3::Divide(Vector3 v)
{
    return Vector3(x/v.x, y/v.y, z/v.z);
}

Vector3 Vector3::Divide(float f)
{
    return Vector3(x/f, y/f, z/f);
}

Vector3 Vector3::Abs()
{
    return Vector3(fabsf(x), fabsf(y), fabsf(z));
}

Vector3 Vector3::Zero()
{
    x = 0;
    y = 0;
    z = 0;
    
    return *this;
}

Vector3 Vector3::One()
{
    x = 1;
    y = 1;
    z = 1;
    
    return *this;
}

Vector3 Vector3::Up()
{
    x = 0;
    y = 1;
    z = 0;
    
    return  *this;
}

Vector3 Vector3::Right()
{
    x = 1;
    y = 0;
    z = 0;
    
    return  *this;
}

Vector3 Vector3::Down()
{
    x = 0;
    y = -1;
    z = 0;
    
    return  *this;
}

Vector3 Vector3::Left()
{
    x = -1;
    y = 0;
    z = 0;
    
    return  *this;
}

Vector3 Vector3::Forward()
{
    x = 0;
    y = 0;
    z = 1;
    
    return  *this;
}

Vector3 Vector3::operator + (Vector3 v)
{
    return Add(v);
}

Vector3 Vector3::operator * (Vector3 v)
{
    return Multiply(v);
}

Vector3 Vector3::operator - ()
{
    x *= -1;
    y *= -1;
    z *= -1;
    
    return  *this;
}

string Vector3::ToString()
{
    return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
}
