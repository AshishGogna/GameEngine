//
//  Shader.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 01/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <iostream>
#include <map>
#include "Matrix4.hpp"
#include "Vector3.hpp"
#include "Material.hpp"

class Shader
{
private:
    GLuint program;
    std::map<std::string, int> uniforms;
    
public:
    Shader();
    
    void AddVertexShader(std::string text);
    void AddGeometryShader(std::string text);
    void AddFragmentShader(std::string text);
    void AddProgram(std::string text, int type);
    void CompileShader();
    void Bind();
    
    void AddUniform(std::string uniform);
    void SetUniformi(std::string uniform, int value);
    void SetUniformf(std::string uniform, float value);
    void SetUniform(std::string uniform, Vector3 value);
    void SetUniform(std::string uniform, Matrix4 value);
    virtual void UpdateUniform(Matrix4 worldMatrix, Matrix4 projectedMatrix, Material material);
};

#endif /* Shader_hpp */
