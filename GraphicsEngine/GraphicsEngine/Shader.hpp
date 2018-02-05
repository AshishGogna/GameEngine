//
//  Shader.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include "Matrix4.hpp"
#include <map>

using namespace std;

class Shader
{
private:
    GLuint program;
    map<string, int> uniforms;
    
    void AddProgram(string shaderCode, int type);
    string LoadShader(string filePath);
    void CompileShader();
    void Init();
    
public:
    Shader();
    Shader(string vertexShaderPath, string fragmentShaderPath);
    
    void AddVertexShaderFromFile(string filePath);
    void AddFragmentShaderFromFile(string filePath);
    void Bind();
    
    void AddUiform(string name);
    void SetUniform(std::string uniform, Matrix4 value);
};

#endif /* Shader_hpp */
