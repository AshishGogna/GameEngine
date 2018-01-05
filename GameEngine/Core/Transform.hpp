//
//  Transform.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 05/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "Vector3.hpp"
#include "Matrix4.hpp"

class Transform
{
public:
    Vector3 translation;
    Vector3 rotation;
    
    Transform();
    
    Matrix4 GetTransformation();
    void SetTranslation(float x, float y, float z);
    void SetRotation(float x, float y, float z);
};

#endif /* Transform_hpp */
