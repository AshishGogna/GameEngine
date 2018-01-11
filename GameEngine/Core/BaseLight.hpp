//
//  BaseLight.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef BaseLight_hpp
#define BaseLight_hpp

#include <stdio.h>
#include "Vector3.hpp"

class BaseLight
{
public:
    Vector3 color;
    float intensity;
    
    BaseLight();
    BaseLight(Vector3 color, float intensity);
};

#endif /* BaseLight_hpp */
