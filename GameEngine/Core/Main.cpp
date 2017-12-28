//
//  Main.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 28/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Main.hpp"
#include "Time.hpp"
#include "Window.hpp"

Main::Main()
{
    isRunning = false;
    game = Game();
}

void Main::Start()
{
    if (isRunning) return;
    Run();
}

void Main::Stop()
{
    if (!isRunning) return;
    isRunning = false;
}

void Main::Run()
{
    isRunning = true;
    int frames = 0;
    long frameCounter = 0;
    const double frameTime = 1 / FRAME_CAP;
    
    long lastTime = Time::GetTime();
    double unprocessedTime = 0;
    
    while (isRunning)
    {
        bool render = false;
        
        long startTime = Time::GetTime();
        long passedTime = startTime - lastTime;
        lastTime = startTime;
        unprocessedTime += passedTime / (double)Time::SECOND;
        frameCounter += passedTime;
        
        while (unprocessedTime > frameTime)
        {
            render = true;
            unprocessedTime -= frameTime;
            if (Window::isCloseRequested()) Stop();
            
            Time::SetDelta(frameTime);
            
            game.Input();
            game.Update();
            
        }
    }
}
