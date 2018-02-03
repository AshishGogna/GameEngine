//
//  MainComponent.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "MainComponent.hpp"
#include "Window.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

MainComponent::MainComponent()
{
    Start();
}

void MainComponent::Start()
{
    Window::CreateWindow();
    Run();
}

void MainComponent::Run()
{
    Mesh m = Mesh();
    
    Shader s = Shader("/Users/ashishgogna/Desktop/Projects/GraphicsEngine/GraphicsEngine/Resources/BasicVertex.glsl", "/Users/ashishgogna/Desktop/Projects/GraphicsEngine/GraphicsEngine/Resources/BasicFragment.glsl");
    s.Bind();

    //Run while ESC key not pressed and the window wasn't closed
    do
    {
        Window::Clear();
        
        m.Draw();

        Window::SwapBuffers();
    }
    while(Window::ShouldClose());
}
