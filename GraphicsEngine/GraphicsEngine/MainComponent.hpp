//
//  MainComponent.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef MainComponent_hpp
#define MainComponent_hpp

#include <stdio.h>
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Camera.hpp"

class MainComponent
{
private:
    Camera camera;
    vector<Mesh> meshes;
    Shader shader;
    
    void Run();
    void Start();
    void Stop();
    void Update();
    void Render();
    void Test();
    
public:
    MainComponent();
};

#endif /* MainComponent_hpp */
