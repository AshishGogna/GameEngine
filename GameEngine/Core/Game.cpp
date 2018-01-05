//
//  Game.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Game.hpp"
#include "ResourceLoader.hpp"
#include "Window.hpp"
#include "Util.hpp"
#include "Time.hpp"
#include <math.h>

Game::Game()
{
    if (!Window::isInitialized()) return;

    //Mesh
    mesh = Mesh();
    vector<Vertex> data{};
    data.push_back(Vertex(Vector3(-1, -1, 0)));
    data.push_back(Vertex(Vector3(1, -1, 0)));
    data.push_back(Vertex(Vector3(0, 1, 0)));
    mesh.AddVertices(data);

    //Shaders
    shader = Shader();
    shader.AddVertexShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/BasicVertex.vs"));
    shader.AddFragmentShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/BasicFragment.fs"));
    shader.CompileShader();
    
    transform = Transform();
    
    shader.AddUniform("transform");
}

void Game::Input()
{
    
}

float temp = 0;
void Game::Update()
{
    temp += Time::delta;
    transform.SetTranslation(sinf(temp), 0, 0);
    transform.SetRotation(0, 0, sinf(temp) * 360);
}

void Game::Render()
{
    shader.Bind();
    
    shader.SetUniform("transform", transform.GetTransformation());
    
    mesh.Draw();
    Window::SwapBuffers();
}
