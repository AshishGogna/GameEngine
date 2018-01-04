//
//  Time.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 28/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>

#endif /* Time_hpp */

class Time
{
public:
    static double delta;
    static const long SECOND = 1000000000L;
    
    static long GetTime();
    static void GetDelta();
    static void SetDelta(double d);
};
