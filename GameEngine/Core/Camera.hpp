//
//  Camera.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 10/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "Vector3.hpp"

class Camera
{
private:
    void Init(Vector3 position, Vector3 forward, Vector3 up);

public:
    Vector3 yAxis = Vector3(0, 1, 0);
    Vector3 position;
    Vector3 forward;
    Vector3 up;
    
    Camera();
    Camera(Vector3 position, Vector3 forward, Vector3 up);
    
    void Input();
    void Move(Vector3 direction, float amount);
    void RotateX(float angle);
    void RotateY(float angle);
    Vector3 GetLeft();
    Vector3 GetRight();
};

#endif /* Camera_hpp */
