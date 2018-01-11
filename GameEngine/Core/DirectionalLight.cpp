//
//  DirectionalLight.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "DirectionalLight.hpp"

DirectionalLight::DirectionalLight()
{
    
}

DirectionalLight::DirectionalLight(BaseLight bl, Vector3 dir)
{
    baseLight = bl;
    direction = dir.Normalized();
}
