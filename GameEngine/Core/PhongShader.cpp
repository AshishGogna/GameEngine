//
//  PhongShader.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "PhongShader.hpp"

#include "RenderUtil.hpp"
#include "Util.hpp"

PhongShader::PhongShader(Transform t)
{
    trns = t;
    
    directionalLight = DirectionalLight(BaseLight(Vector3(1, 1, 1), 0), Vector3(0, 0, 0));
    
    AddVertexShaderFromFile("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/PhongVertex.vs");
    AddFragmentShaderFromFile("/Users/ashishgogna/Desktop/Projects/GameEngine/GameEngine/Resources/Shaders/PhongFragment.fs");
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
    
    for (int i=0; i<MAX_POINT_LIGHTS; i++)
    {
        AddUniform("pointLights[" + to_string(i) + "].bl.color");
        AddUniform("pointLights[" + to_string(i) + "].bl.intensity");
        AddUniform("pointLights[" + to_string(i) + "].atten.constant");
        AddUniform("pointLights[" + to_string(i) + "].atten.linear");
        AddUniform("pointLights[" + to_string(i) + "].atten.exponent");
        AddUniform("pointLights[" + to_string(i) + "].position");
        AddUniform("pointLights[" + to_string(i) + "].range");
    }

    for (int i=0; i<MAX_SPOT_LIGHTS; i++)
    {
        AddUniform("spotLights[" + to_string(i) + "].pl.bl.color");
        AddUniform("spotLights[" + to_string(i) + "].pl.bl.intensity");
        AddUniform("spotLights[" + to_string(i) + "].pl.atten.constant");
        AddUniform("spotLights[" + to_string(i) + "].pl.atten.linear");
        AddUniform("spotLights[" + to_string(i) + "].pl.atten.exponent");
        AddUniform("spotLights[" + to_string(i) + "].pl.position");
        AddUniform("spotLights[" + to_string(i) + "].pl.range");
        AddUniform("spotLights[" + to_string(i) + "].direction");
        AddUniform("spotLights[" + to_string(i) + "].cutoff");
    }
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
    SetUniformf("specularIntensity", material.specularIntensity);
    SetUniformf("specularExponent", material.specularExponent);
    SetUniform("eyePos", trns.camera.position);

    SetUniformDirectionalLight("directionalLight", directionalLight);
    
    for (int i=0; i<pointLights.size(); i++)
        SetUniformPointLight("pointLights[" + to_string(i) + "]", pointLights[i]);

    for (int i=0; i<spotLights.size(); i++)
        SetUniformSpotLight("spotLights[" + to_string(i) + "]", spotLights[i]);
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

void PhongShader::SetUniformPointLight(std::string uniform, PointLight pl)
{
    SetUniformBaseLight(uniform + ".bl", pl.bl);
    SetUniformf(uniform + ".atten.constant", pl.atten.constant);
    SetUniformf(uniform + ".atten.linear", pl.atten.linear);
    SetUniformf(uniform + ".atten.exponent", pl.atten.exponent);
    SetUniform(uniform + ".position", pl.position);
    SetUniformf(uniform + ".range", pl.range);
}

void PhongShader::SetUniformSpotLight(std::string uniform, SpotLight sl)
{
    SetUniformPointLight(uniform + ".pl", sl.pl);
    SetUniform(uniform + ".direction", sl.direction);
    SetUniformf(uniform + ".cutoff", sl.cutoff);
}

void PhongShader::SetPointLights(vector<PointLight> pls)
{
    if (pls.size() > MAX_POINT_LIGHTS)
    {
        Util::Print("Too many point lights. \nMax allowed: " + to_string(MAX_POINT_LIGHTS));
        Util::Exit();
    }
    
    pointLights = pls;
}

void PhongShader::SetSpotLights(vector<SpotLight> sls)
{
    if (sls.size() > MAX_SPOT_LIGHTS)
    {
        Util::Print("Too many spot lights. \nMax allowed: " + to_string(MAX_SPOT_LIGHTS));
        Util::Exit();
    }
    
    spotLights = sls;
}
