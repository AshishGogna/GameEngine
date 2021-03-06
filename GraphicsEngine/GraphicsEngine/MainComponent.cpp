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
    Test();

    //Main Loop
    do
    {
        Update();
        Render();
    }
    while(Window::ShouldClose());
    
    Stop();
}

void MainComponent::Test()
{
    camera = Camera(70, 0.1, 1000);
    
    vector<Vertex> vertices0{};
    vertices0.push_back(Vertex(Vector3(-1, -1, 0)));
    vertices0.push_back(Vertex(Vector3(1, -1, 0)));
    vertices0.push_back(Vertex(Vector3(0, 1, 0)));
    vertices0.push_back(Vertex(Vector3(0, -1, -1)));
    vector<int> indices0 = {0, 1, 2, 2, 0, 3, 3, 1, 2, 0, 1, 3};
    meshes.push_back(Mesh(0, vertices0, indices0));
    
    vector<Vertex> vertices1{};
    vertices1.push_back(Vertex(Vector3(-1, -1, 0)));
    vertices1.push_back(Vertex(Vector3(1, -1, 0)));
    vertices1.push_back(Vertex(Vector3(0, 1, 0)));
    vertices1.push_back(Vertex(Vector3(0, -1, -1)));
    vector<int> indices1 = {0, 1, 2, 2, 0, 3, 3, 1, 2, 0, 1, 3};
    meshes.push_back(Mesh(1, vertices1, indices1));
    
    meshes[0].transform.Translate(Vector3(-1, 0, 5));
    meshes[1].transform.Translate(Vector3(5, 0, 5));
    
    shader = Shader("/Users/ashishgogna/Desktop/Projects/GraphicsEngine/GraphicsEngine/Resources/BasicVertex.glsl", "/Users/ashishgogna/Desktop/Projects/GraphicsEngine/GraphicsEngine/Resources/BasicFragment.glsl");
    shader.Bind();
    shader.AddUiform("mvp");
}

void MainComponent::Update()
{
    camera.Update();
    //meshes[0].transform.Rotate(10, Vector3(1, 0, 0));
}

void MainComponent::Render()
{
    Window::Clear();
    
    shader.SetUniform("mvp", camera.GetMvpMatrix(meshes));
    
    for (int i=0; i<meshes.size(); i++)
    {
        meshes[i].Draw();
    }
    
    Window::SwapBuffers();
}
