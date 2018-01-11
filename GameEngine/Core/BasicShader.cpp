//
//  BasicShader.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "BasicShader.hpp"
#include "ResourceLoader.hpp"
#include "RenderUtil.hpp"

BasicShader::BasicShader()
{
    AddVertexShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/BasicVertex.vs"));
    AddFragmentShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/BasicFragment.fs"));
    CompileShader();

    AddUniform("transform");
    AddUniform("color");
}

void BasicShader::UpdateUniform(Matrix4 worldMatrix, Matrix4 projectedMatrix, Material material)
{
    cout << "? = " << material.texture.GetId() << endl;

    if (material.texture.GetId() != 0)
        material.texture.Bind();
    else
        RenderUtil::UnbindTextures();
    
    SetUniform("transform", projectedMatrix);
    SetUniform("color", material.color);
}
