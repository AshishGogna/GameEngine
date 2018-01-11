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
#include "RenderUtil.hpp"
#include "Texture.hpp"

Game::Game()
{
    if (!Window::isInitialized()) return;

    //Mesh
    mesh = Mesh(); //ResourceLoader::LoadMesh("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Models/Cube.obj");
    shader = new PhongShader();
    material = Material(ResourceLoader::LoadTexture("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Textures/Checker.bmp"), Vector3(1, 1, 1));
    transform = Transform();
    
    vector<Vertex> vertices{};
    vertices.push_back(Vertex(Vector3(-1, -1, 0), Vector2(0, 0)));
    vertices.push_back(Vertex(Vector3(0, 1, 0), Vector2(0.5, 0)));
    vertices.push_back(Vertex(Vector3(1, -1, 0), Vector2(1, 0)));
    vertices.push_back(Vertex(Vector3(0, -1, 1), Vector2(0, 0.5)));
    vector<int> indices = {3,1,0,2,1,3,0,1,2,0,2,3};
    mesh.AddVertices(vertices, indices);
    
    transform.SetProjection(70, Window::width, Window::height, 0.1, 1000);
    transform.SetTranslation(0, 0, 5);
    
    static_cast<PhongShader*>(shader)->AmbientLight = Vector3(0.1, 0.1, 0.5);
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
    RenderUtil::SetClearColor(transform.camera.position.Divide(2048).Abs());

    shader->Bind();
    shader->UpdateUniform(transform.GetTransformation(), transform.GetProjectedTransformation(), material);
    mesh.Draw();
    
    Window::SwapBuffers();
}

void Game::CleanUp()
{
    delete shader;
}
