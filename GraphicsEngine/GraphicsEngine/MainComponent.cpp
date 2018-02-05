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
    
    Mesh m = Mesh(vertices, indices);
    m.transform.Translate(Vector3(0.2, 0, 0));
    //m.transform.GetTransformationMatrix();
    
    Shader s = Shader("/Users/ashishgogna/Desktop/Projects/GraphicsEngine/GraphicsEngine/Resources/BasicVertex.glsl", "/Users/ashishgogna/Desktop/Projects/GraphicsEngine/GraphicsEngine/Resources/BasicFragment.glsl");
    s.Bind();
    
    s.AddUiform("transform");

    do
    {
        Window::Clear();
        
        Util::Print(m.transform.GetTransformationMatrix().ToString());
        s.SetUniform("transform", m.transform.GetTransformationMatrix());
        
        m.Draw();

        Window::SwapBuffers();
    }
    while(Window::ShouldClose());
    
    Stop();
}
