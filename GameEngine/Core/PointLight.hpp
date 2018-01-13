//
//  PointLight.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 12/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef PointLight_hpp
#define PointLight_hpp

#include <stdio.h>
#include "BaseLight.hpp"
#include "Attenuation.hpp"

class PointLight
{
public:
    BaseLight bl;
    Attenuation atten;
    Vector3 position;
    float range;
    
    PointLight();
    PointLight(BaseLight bl, Attenuation atten, Vector3 pos, float range);
};

#endif /* PointLight_hpp */
