//
//  Vector3.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Vector3.hpp"
#include <math.h>
#include "Quaternion.hpp"

Vector3::Vector3()
{
    
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

Vector3 Vector3::Normalize()
{
    float length = Length();
    x /= length;
    y /= length;
    z /= length;
    
    return *this;
}

Vector3 Vector3::Rotate(float angle, Vector3 axis)
{
    float sinHalfAngle = sinf((angle/2) * (M_PI/180));
    float cosHalfAngle = cosf((angle/2) * (M_PI/180));
    
    float rx = axis.x * sinHalfAngle;
    float ry = axis.y * sinHalfAngle;
    float rz = axis.z * sinHalfAngle;
    float rw = cosHalfAngle;

    Quaternion rot = Quaternion(rx, ry, rz, rw);
    Quaternion conjugate = rot.Conjugate();
    Quaternion w = rot.Multiply(*this).Multiply(conjugate);

    x = w.x;
    y = w.y;
    z = w.z;
    
    return *this;
}

//Addition
Vector3 Vector3::Add(Vector3 v)
{
    return Vector3(x+v.x, y+v.y, z+v.z);
}
Vector3 Vector3::Add(float f)
{
    return Vector3(x+f, y+f, z+f);
}

//Subtraction
Vector3 Vector3::Subtract(Vector3 v)
{
    return Vector3(x-v.x, y-v.y, z-v.z);
}
Vector3 Vector3::Subtract(float f)
{
    return Vector3(x-f, y-f, z-f);
}

//Multiplication
Vector3 Vector3::Multiply(Vector3 v)
{
    return Vector3(x*v.x, y*v.y, z*v.z);
}
Vector3 Vector3::Multiply(float f)
{
    return Vector3(x*f, y*f, z*f);
}

//Division
Vector3 Vector3::Divide(Vector3 v)
{
    return Vector3(x/v.x, y/v.y, z/v.z);
}
Vector3 Vector3::Divide(float f)
{
    return Vector3(x/f, y/f, z/f);
}

string Vector3::ToString()
{
    return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
}
