//
//  Game.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Mesh.hpp"
#include "BasicShader.hpp"
#include "PhongShader.hpp"
#include "Transform.hpp"
#include "Material.hpp"

#endif /* Game_hpp */

class Game
{
private:
    Mesh mesh;
    Shader *shader;
    Transform transform;
    Material material;
    
    PointLight pl1 = PointLight(BaseLight(Vector3(1, 0.5, 0), 0.8), Attenuation(0, 0, 1), Vector3(-2, 0, 5), 5);
    PointLight pl2 = PointLight(BaseLight(Vector3(0, 0.5, 1), 0.8), Attenuation(0, 0, 1), Vector3(2, 0, 7), 5);
    vector<PointLight> pls = {pl1, pl2};

    SpotLight sl1 = SpotLight(PointLight(BaseLight(Vector3(0, 1, 1), 0.8), Attenuation(0, 0, 0.1), Vector3(-2, 0, 5), 30),
                              Vector3(1, 1, 1), 0.7);
    vector<SpotLight> sls = {sl1};

public:
    Game();
    
    void Input();
    void Update();
    void Render();
    void CleanUp();
};
