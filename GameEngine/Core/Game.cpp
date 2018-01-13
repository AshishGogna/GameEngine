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
    material = Material(ResourceLoader::LoadTexture("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Textures/Checker.bmp"), Vector3(1, 1, 1), 1, 8);
    transform = Transform();
    shader = new PhongShader(transform);
    
    /*
    vector<Vertex> vertices{};
    vertices.push_back(Vertex(Vector3(-1, -1, 0), Vector2(0, 0)));
    vertices.push_back(Vertex(Vector3(0, 1, 0), Vector2(0.5, 0)));
    vertices.push_back(Vertex(Vector3(1, -1, 0), Vector2(1, 0)));
    vertices.push_back(Vertex(Vector3(0, -1, 1), Vector2(0, 0.5)));
    vector<int> indices = {3,1,0,2,1,3,0,1,2,0,2,3};
    mesh.AddVertices(vertices, indices, true);
     */

    float fieldDepth = 10;
    float fieldWidth = 10;
    vector<Vertex> vertices = {
        Vertex(Vector3(-fieldWidth, 0, -fieldDepth), Vector2(0, 0)),
        Vertex(Vector3(-fieldWidth, 0, fieldDepth*3), Vector2(0, 1)),
        Vertex(Vector3(fieldWidth*3, 0, -fieldDepth), Vector2(1, 0)),
        Vertex(Vector3(fieldWidth*3, 0, fieldDepth*3), Vector2(1, 1))
    };
    vector<int> indices = {0,1,2,2,1,3};
    mesh.AddVertices(vertices, indices, true);
    
    transform.SetProjection(70, Window::width, Window::height, 0.1, 1000);
    transform.SetTranslation(0, 0, 5);
    
    static_cast<PhongShader*>(shader)->ambientLight = Vector3(0.1, 0.1, 0.1);
    //static_cast<PhongShader*>(shader)->directionalLight = DirectionalLight(BaseLight(Vector3(1, 1, 1), 0.7), Vector3(1, 1, 1));
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
    
    transform.SetTranslation(0, -1, 5);
    //transform.SetRotation(0, sinTemp * 360, 0);
    //transform.SetScale(0.7*sinTemp, 0.7*sinTemp, 0.7*sinTemp);
    
    //pls[0].position = Vector3(3, 0, 8*(sinf(temp)+1/2) + 10);
    //pls[1].position = Vector3(7, 0, 8*(cosf(temp)+1/2) + 10);
    //static_cast<PhongShader*>(shader)->SetPointLights(pls);

    sls[0].pl.position = transform.camera.position;
    sls[0].direction = transform.camera.forward;
    static_cast<PhongShader*>(shader)->SetSpotLights(sls);
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
