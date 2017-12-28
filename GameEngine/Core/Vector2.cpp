//
//  Vector2.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Vector2.hpp"
#include <math.h>

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2::Length()
{
    return sqrtf((x*x) + (y*y));
}

float Vector2::Dot(Vector2 v)
{
    return (x*v.x + y*v.y);
}

Vector2 Vector2::Normalize()
{
    float length = Length();
    x /= length;
    y /= length;
    
    return *this;
}

Vector2 Vector2::Rotate(float angle)
{
    double radians = angle * (M_PI/180);
    double cos = cosh(radians);
    double sin = sinh(radians);
    
    return Vector2(x*cos - y*sin, x*sin+y*cos);
}

//Addition
Vector2 Vector2::Add(Vector2 v)
{
    return Vector2(x+v.x, y+v.y);
}
Vector2 Vector2::Add(float f)
{
    return Vector2(x+f, y+f);
}

//Subtraction
Vector2 Vector2::Subtract(Vector2 v)
{
    return Vector2(x-v.x, y-v.y);
}
Vector2 Vector2::Subtract(float f)
{
    return Vector2(x-f, y-f);
}

//Multiplication
Vector2 Vector2::Multiply(Vector2 v)
{
    return Vector2(x*v.x, y*v.y);
}
Vector2 Vector2::Multiply(float f)
{
    return Vector2(x*f, y*f);
}

//Division
Vector2 Vector2::Divide(Vector2 v)
{
    return Vector2(x/v.x, y/v.y);
}
Vector2 Vector2::Divide(float f)
{
    return Vector2(x/f, y/f);
}

//Just for debugging
string Vector2::ToString()
{
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}
