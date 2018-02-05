//
//  Quaternion.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 05/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Quaternion_hpp
#define Quaternion_hpp

#include <stdio.h>
#include "Vector3.hpp"

class Quaternion
{
public:
    float x, y, z, w;
    
    Quaternion();
    Quaternion(float x, float y, float z, float w);
    
    float Length();
    Quaternion Normalize();
    Quaternion Conjugate();
    Quaternion Multiply(Quaternion q);
    Quaternion Multiply(Vector3 v);
};

#endif /* Quaternion_hpp */
