//
//  Material.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Material_hpp
#define Material_hpp

#include <stdio.h>
#include "Texture.hpp"
#include "Vector3.hpp"

class Material
{
private:
    
public:
    Texture texture;
    Vector3 color = Vector3(1, 1, 1);
    float specularIntensity = 2;
    float specularExponent = 32;
    
    Material();
    Material(Texture tex, Vector3 col);
    Material(Texture tex, Vector3 col, float specIntensity, float specExponent);
};

#endif /* Material_hpp */
