//
//  Shader.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 01/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Shader.hpp"
#include <vector>

Shader::Shader()
{
    program = glCreateProgram();
    if (program == 0)
    {
        std::cout << "Shader creation failed." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Shader::AddVertexShader(std::string text)
{
    AddProgram(text, GL_VERTEX_SHADER);
}

void Shader::AddGeometryShader(std::string text)
{
    AddProgram(text, GL_GEOMETRY_SHADER);
}

void Shader::AddFragmentShader(std::string text)
{
    AddProgram(text, GL_FRAGMENT_SHADER);
}

void Shader::AddProgram(std::string text, int type)
{
    GLuint shader = glCreateShader(type);
    
    if (shader == 0)
    {
        if (program == 0) std::cout << "Shader creation failed when adding shader." << std::endl;
        exit(EXIT_FAILURE);
    }
    
    const char *textPointer = text.c_str();
    glShaderSource(shader, 1, &textPointer, NULL);
    glCompileShader(shader);
    
    GLint compileResult = GL_FALSE;
    int  infoLog;
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);
    if (compileResult == 0)
    {
        std::vector<char> shaderErrorMessage(infoLog+1);
        glGetShaderInfoLog(shader, infoLog, NULL, &shaderErrorMessage[0]);
        std::cout << &shaderErrorMessage[0] << std::endl;
        exit(EXIT_FAILURE);
    }
    
    //glAttachShader(shader, program);
    glAttachShader(program, shader);
}

void Shader::CompileShader()
{
    GLint result = GL_FALSE;
    
    glLinkProgram(program); //Link and check
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    if (result == 0)
    {int infoLog;
        
        std::vector<char> programErrorMessage(infoLog+1);
        glGetProgramInfoLog(program, infoLog, NULL, &programErrorMessage[0]);
        std::cout << &programErrorMessage[0] << std::endl;
        exit(EXIT_FAILURE);
    }
    
    glValidateProgram(program); // Validate and check
    glGetProgramiv(program, GL_VALIDATE_STATUS, &result);
    if (result == 0)
    {
        int infoLog;
        std::vector<char> programErrorMessage(infoLog+1);
        glGetProgramInfoLog(program, infoLog, NULL, &programErrorMessage[0]);
        std::cout << &programErrorMessage[0] << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Shader::Bind()
{
    glUseProgram(program);
}
