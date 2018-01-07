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
    mesh = ResourceLoader::LoadMesh("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Models/Cube.obj");
    
    /*
    mesh = Mesh();
    vector<Vertex> vertices{};
    vertices.push_back(Vertex(Vector3(-1, -1, 0)));
    vertices.push_back(Vertex(Vector3(0, 1, 0)));
    vertices.push_back(Vertex(Vector3(1, -1, 0)));
    vertices.push_back(Vertex(Vector3(0, -1, 1)));
    
    vector<int> indices = {0,1,3,3,1,2,2,1,0,0,2,3};
    
    mesh.AddVertices(vertices, indices);
    */
    
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
    
    float sinTemp = sinf(temp);
    
    //transform.SetTranslation(sinTemp, 0, 0);
    transform.SetRotation(0, sinTemp * 360, 0);
    transform.SetScale(0.7*sinTemp, 0.7*sinTemp, 0.7*sinTemp);
}

void Game::Render()
{
    shader.Bind();
    
    shader.SetUniform("transform", transform.GetTransformation());
    
    mesh.Draw();
    Window::SwapBuffers();
}
