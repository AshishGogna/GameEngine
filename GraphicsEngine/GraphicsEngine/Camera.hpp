//
//  Camera.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 05/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "Transform.hpp"
#include <vector>
#include "Mesh.hpp"

class Camera
{
private:
    float fov;
    float zNear;
    float zFar;
public:
    Transform transform;
    
    Camera();
    Camera(float fov, float zNear, float zFar);
    
    Matrix4 GetMvpMatrix(vector<Mesh> meshes);
    void Update();
};

#endif /* Camera_hpp */
