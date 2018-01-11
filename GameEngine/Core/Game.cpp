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
#include "Vector2.hpp"

Game::Game()
{
    if (!Window::isInitialized()) return;

    //Mesh
    mesh = Mesh(); //ResourceLoader::LoadMesh("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Models/Cube.obj");
    shader = Shader();
    texture = ResourceLoader::LoadTexture("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Textures/Checker.bmp");
    
    vector<Vertex> vertices{};
    vertices.push_back(Vertex(Vector3(-1, -1, 0), Vector2(0, 0)));
    vertices.push_back(Vertex(Vector3(0, 1, 0), Vector2(0.5, 0)));
    vertices.push_back(Vertex(Vector3(1, -1, 0), Vector2(1, 0)));
    vertices.push_back(Vertex(Vector3(0, -1, 1), Vector2(0, 0.5)));
    vector<int> indices = {3,1,0,2,1,3,0,1,2,0,2,3};
    mesh.AddVertices(vertices, indices);
    
    //Shaders
    shader.AddVertexShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/BasicVertex.vs"));
    shader.AddFragmentShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/BasicFragment.fs"));
    shader.CompileShader();
    
    transform = Transform();
    transform.SetProjection(70, Window::width, Window::height, 0.1, 1000);
    transform.SetTranslation(0, 0, 5);
    
    shader.AddUniform("transform");
}

void Game::Input()
{
    transform.camera.Input();
}

float temp = 0;
void Game::Update()
{
    temp += Time::delta;
    
    float sinTemp = sinf(temp);
    
    //transform.SetTranslation(sinTemp, 0, 5);
    transform.SetRotation(0, sinTemp * 360, 0);
    //transform.SetScale(0.7*sinTemp, 0.7*sinTemp, 0.7*sinTemp);
}

void Game::Render()
{
    shader.Bind();
    shader.SetUniform("transform", transform.GetProjectedTransformation());
    texture.Bind();
    mesh.Draw();
    Window::SwapBuffers();
}
