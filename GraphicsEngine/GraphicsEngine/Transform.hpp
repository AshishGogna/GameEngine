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
private:
    void UpdateDirections();
    
public:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    Vector3 up;
    Vector3 right;
    Vector3 forward;
    
    Transform();
    
    void Translate(Vector3 by);
    void Rotate(float angle, Vector3 axis);
    void Scale(Vector3 by);
    Matrix4 GetTransformationMatrix();
};

#endif /* Transform_hpp */
