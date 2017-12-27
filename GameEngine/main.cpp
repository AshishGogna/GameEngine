//
//  main.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 26/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "GEWindow.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    GEWindow window = GEWindow();
    while (!window.isCloseRequested())
    {
        window.Clear();
    }
    window.Terminate();
    
    return 0;
}
