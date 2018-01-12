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

PhongShader::PhongShader(Transform t)
{
    trns = t;
    
    directionalLight = DirectionalLight(BaseLight(Vector3(1, 1, 1), 0), Vector3(0, 0, 0));
    
    AddVertexShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/PhongVertex.vs"));
    AddFragmentShader(ResourceLoader::LoadShader("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/PhongFragment.fs"));
    CompileShader();
    
    AddUniform("transform");
    AddUniform("transformProjected");
    AddUniform("baseColor");
    AddUniform("ambientLight");
    AddUniform("specularIntensity");
    AddUniform("specularExponent");
    AddUniform("eyePos");
    AddUniform("ambientLight");
    
    AddUniform("directionalLight.baseLight.color");
    AddUniform("directionalLight.baseLight.intensity");
    AddUniform("directionalLight.direction");
}

void PhongShader::UpdateUniform(Matrix4 worldMatrix, Matrix4 projectedMatrix, Material material)
{
    if (material.texture.GetId() != 0)
        material.texture.Bind();
    else
        RenderUtil::UnbindTextures();
    
    SetUniform("transform", worldMatrix);
    SetUniform("transformProjected", projectedMatrix);
    SetUniform("baseColor", material.color);
    SetUniform("ambientLight", ambientLight);
    SetUniformDirectionalLight("directionalLight", directionalLight);
    SetUniformf("specularIntensity", material.specularIntensity);
    SetUniformf("specularExponent", material.specularExponent);
    SetUniform("eyePos", trns.camera.position);
}

void PhongShader::SetUniformBaseLight(std::string uniform, BaseLight bl)
{
    SetUniform(uniform + ".color", bl.color);
    SetUniformf(uniform + ".intensity", bl.intensity);
}

void PhongShader::SetUniformDirectionalLight(std::string uniform, DirectionalLight dl)
{
    SetUniform(uniform + ".direction", dl.direction);
    SetUniformBaseLight(uniform + ".baseLight", dl.baseLight);
}
