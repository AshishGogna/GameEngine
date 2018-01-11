//
//  DirectionalLight.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef DirectionalLight_hpp
#define DirectionalLight_hpp

#include <stdio.h>
#include "BaseLight.hpp"
#include "Vector3.hpp"

class DirectionalLight
{
public:
    BaseLight baseLight;
    Vector3 direction;
    
    DirectionalLight();
    DirectionalLight(BaseLight bl, Vector3 dir);
};

#endif /* DirectionalLight_hpp */
