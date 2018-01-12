//
//  Material.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Material.hpp"

Material::Material()
{
    
}

Material::Material(Texture tex, Vector3 col)
{
    texture = tex;
    color = col;
}

Material::Material(Texture tex, Vector3 col, float specIntensity, float specExponent)
{
    texture = tex;
    color = col;
    specularIntensity = specIntensity;
    specularExponent = specExponent;
}
