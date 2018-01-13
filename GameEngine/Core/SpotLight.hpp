//
//  SpotLight.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 13/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef SpotLight_hpp
#define SpotLight_hpp

#include <stdio.h>
#include "PointLight.hpp"

class SpotLight
{
public:
    PointLight pl;
    Vector3 direction;
    float cutoff;
    
    SpotLight();
    SpotLight(PointLight pl, Vector3 dir, float cutoff);
};

#endif /* SpotLight_hpp */
