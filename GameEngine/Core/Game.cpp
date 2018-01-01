//
//  Game.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Game.hpp"

Game::Game()
{
    mesh = Mesh();

    vector<Vertex> data{};
    data.push_back(Vertex(Vector3(-1, -1, 0)));
    data.push_back(Vertex(Vector3(0, 1, 0)));
    data.push_back(Vertex(Vector3(-1, 1, 0)));
    
    mesh.AddVertices(data);
}

void Game::Input()
{
    
}

void Game::Update()
{
    
}

void Game::Render()
{
    mesh.Draw();
}
