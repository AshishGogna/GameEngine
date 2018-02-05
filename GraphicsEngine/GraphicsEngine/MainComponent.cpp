//
//  MainComponent.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "MainComponent.hpp"
#include "Window.hpp"
#include "Util.hpp"

MainComponent::MainComponent()
{
    Start();
}

void MainComponent::Start()
{
    Window::CreateWindow();
    Run();
}

void MainComponent::Stop()
{
    Window::Terminate();
}

void MainComponent::Run()
{
    vector<Vertex> vertices{};
    vertices.push_back(Vertex(Vector3(-1, -1, 0)));
    vertices.push_back(Vertex(Vector3(1, -1, 0)));
    vertices.push_back(Vertex(Vector3(0, 1, 0)));
    vector<int> indices = {0, 1, 2};
    mesh = Mesh(vertices, indices);
    mesh.transform.Scale(Vector3(1, 0.5, 0.2));
    
    shader = Shader("/Users/ashishgogna/Desktop/Projects/GraphicsEngine/GraphicsEngine/Resources/BasicVertex.glsl", "/Users/ashishgogna/Desktop/Projects/GraphicsEngine/GraphicsEngine/Resources/BasicFragment.glsl");
    shader.Bind();
    shader.AddUiform("transform");

    //Main Loop
    do
    {
        Update();
        Render();
    }
    while(Window::ShouldClose());
    
    Stop();
}

void MainComponent::Update()
{
    //mesh.transform.Translate(Vector3(0.5, 0, 0));
    //mesh.transform.Rotate(Vector3(0, 0, 1));
}

void MainComponent::Render()
{
    Window::Clear();
    
    shader.SetUniform("transform", mesh.transform.GetTransformationMatrix());
    mesh.Draw();
    
    Window::SwapBuffers();

}
