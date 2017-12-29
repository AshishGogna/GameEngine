//
//  Time.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 28/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//
// TODO: I guess the nanoseconds aren't correct yet.

#include "Time.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

double Time::delta;

long Time::GetTime()
{
    time_t curr = system_clock::to_time_t(system_clock::now());
    seconds s(curr);
    nanoseconds ns = duration_cast<nanoseconds>(s);
    
    //cout << s.count() << endl;
    //cout << (long)ns.count() << endl;
    
    auto duration = system_clock::now().time_since_epoch();
    auto m = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    
    //cout << " = " << m << endl;

    return m;
}

void Time::SetDelta(double d)
{
    delta = d;
}
