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
#include "Input.hpp"
#include <thread>
#include "RenderUtil.hpp"

Main::Main()
{
    Window::CreateWindow(WIDTH, HEIGHT, TITLE);
    RenderUtil::InitGraphics();

    cout << RenderUtil::GetOpenGLVersion() << endl;

    isRunning = false;
}

void Main::Start()
{
    game = Game();
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
            Input::Update();
            game.Update();
            
            if (frameCounter >= Time::SECOND)
            {
                cout << "Check: " << frames << endl;
                frames = 0;
                frameCounter = 0;
            }
        }
        
        if (render)
        {
            Render();
            frames++;
        }
        else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    
    CleanUp();
}

void Main::Render()
{
    Window::Render();
    RenderUtil::ClearScreen();
    game.Render();
}

void Main::CleanUp()
{
    Window::Dispose();
    
}
