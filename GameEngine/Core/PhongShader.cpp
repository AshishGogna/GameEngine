//
//  PhongShader.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "PhongShader.hpp"

#include "ResourceLoader.hpp"
#include "RenderUtil.hpp"

PhongShader::PhongShader()
{
    AddVertexShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/PhongVertex.vs"));
    AddFragmentShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/PhongFragment.fs"));
    CompileShader();
    
    AddUniform("transform");
    AddUniform("baseColor");
    AddUniform("ambientLight");
}

void PhongShader::UpdateUniform(Matrix4 worldMatrix, Matrix4 projectedMatrix, Material material)
{
    cout << "? = " << material.texture.GetId() << endl;
    
    if (material.texture.GetId() != 0)
        material.texture.Bind();
    else
        RenderUtil::UnbindTextures();
    
    SetUniform("transform", projectedMatrix);
    SetUniform("baseColor", material.color);
    SetUniform("ambientLight", AmbientLight);
}
