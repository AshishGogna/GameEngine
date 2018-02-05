//
//  Transform.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 04/02/18.
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
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    
    Transform();
    
    void Translate(Vector3 by);
    void Rotate(Vector3 by);
    void Scale(Vector3 by);
    Matrix4 GetTransformationMatrix();
};

#endif /* Transform_hpp */
