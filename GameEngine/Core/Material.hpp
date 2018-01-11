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
    Vector3 color;
    
    Material();
    Material(Texture tex, Vector3 col);
};

#endif /* Material_hpp */
