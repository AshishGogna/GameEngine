//
//  Main.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 28/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Main_hpp
#define Main_hpp

#include <stdio.h>
#include <iostream>
#include "Game.hpp"

#endif /* Main_hpp */

using namespace std;

class Main
{
private:
    bool isRunning;
    Game game;
    
public:
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const string TITLE = "Gogna Engine";
    const double FRAME_CAP = 5000.0;

    Main();
    
    void Start();
    void Stop();
    void Run();
    void Render();
    void CleanUp();
    
};
