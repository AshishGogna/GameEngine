//
//  Attenuation.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 12/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Attenuation_hpp
#define Attenuation_hpp

#include <stdio.h>

class Attenuation
{
public:
    float constant;
    float linear;
    float exponent;

    Attenuation();
    Attenuation(float cons, float lin, float exp);
};

#endif /* Attenuation_hpp */
