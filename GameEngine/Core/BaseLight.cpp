//
//  BaseLight.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "BaseLight.hpp"

BaseLight::BaseLight()
{
    
}

BaseLight::BaseLight(Vector3 color, float intensity)
{
    this->color = color;
    this->intensity = intensity;
}
