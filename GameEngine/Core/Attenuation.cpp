//
//  Attenuation.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 12/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Attenuation.hpp"

Attenuation::Attenuation()
{
    
}

Attenuation::Attenuation(float cons, float lin, float exp)
{
    constant = cons;
    linear = lin;
    exponent = exp;
}
