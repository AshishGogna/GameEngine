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
private:
    float zNear;
    float zFar;
    float width;
    float height;
    float fov; //field of view
    
public:
    Vector3 translation;
    Vector3 rotation;
    Vector3 scale;
    
    Transform();
    
    Matrix4 GetTransformation();
    Matrix4 GetProjectedTransformation();
    void SetTranslation(float x, float y, float z);
    void SetRotation(float x, float y, float z);
    void SetScale(float x, float y, float z);
    
    void SetProjection(float fov, float width, float height, float zNear, float zFar);
};

#endif /* Transform_hpp */
