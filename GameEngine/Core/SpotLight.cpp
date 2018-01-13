//
//  SpotLight.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 13/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "SpotLight.hpp"

SpotLight::SpotLight()
{
    
}

SpotLight::SpotLight(PointLight pl, Vector3 dir, float cutoff)
{
    this->pl = pl;
    direction = dir.Normalized();
    this->cutoff = cutoff;
}
