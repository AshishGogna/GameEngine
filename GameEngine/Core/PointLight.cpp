//
//  PointLight.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 12/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "PointLight.hpp"

PointLight::PointLight()
{
    
}

PointLight::PointLight(BaseLight bl, Attenuation atten, Vector3 pos)
{
    this->bl = bl;
    this->atten = atten;
    position = pos;
}
