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
#include "Shader.hpp"
#include "Transform.hpp"
#include "Texture.hpp"

#endif /* Game_hpp */

class Game
{
private:
    Mesh mesh;
    Shader shader;
    Transform transform;
    Texture texture;
    
public:
    Game();
    
    void Input();
    void Update();
    void Render();
};
