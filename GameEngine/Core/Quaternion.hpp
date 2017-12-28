//
//  Quaternion.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 28/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Quaternion_hpp
#define Quaternion_hpp

#include <stdio.h>
#include "Vector3.hpp"

#endif /* Quaternion_hpp */

class Quaternion
{
private:
    
public:
    float x, y, z, w;

    Quaternion(float x, float y, float z, float w);

    float Length();
    Quaternion Normalize();
    Quaternion Conjugate();
    
    Quaternion Multiply(Quaternion q);
    Quaternion Multiply(Vector3 v);    
};
