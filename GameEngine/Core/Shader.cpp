//
//  Shader.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 01/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Shader.hpp"
#include <vector>
#include "Window.hpp"
#include "Util.hpp"

Shader::Shader()
{
    if (!Window::isInitialized()) return;

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
    GLuint VertexShaderID = glCreateShader(type);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    char const * VertexSourcePointer = text.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);
    
    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }

    glAttachShader(program, VertexShaderID);
}

void Shader::CompileShader()
{
    GLint Result = GL_FALSE;
    int InfoLogLength;

    glLinkProgram(program);
    
    // Check the program
    glGetProgramiv(program, GL_LINK_STATUS, &Result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(program, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }
    
    /*
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
    */
}

void Shader::Bind()
{
    glUseProgram(program);
}

void Shader::AddUniform(std::string uniform)
{
    GLint uniformLocation = glGetUniformLocation(program, uniform.c_str());

    if (uniformLocation == 0xFFFFFFFF)
    {
        Util::Print("Could not find uniform :" + uniform);
        Util::Exit();
    }
    
    uniforms[uniform] = uniformLocation;
}

void Shader::SetUniformi(std::string uniform, int value)
{
    glUniform1i(uniforms[uniform], value);
}

void Shader::SetUniformf(std::string uniform, float value)
{
    glUniform1f(uniforms[uniform], value);
}

void Shader::SetUniform(std::string uniform, Vector3 value)
{
    glUniform3f(uniforms[uniform], value.x, value.y, value.z);
}

void Shader::SetUniform(std::string uniform, Matrix4 value)
{
    int size = 4*4;
    GLfloat buffer[size];

    //Matrix to buffer
    int k = 0;
    while (k < size)
    {
        for (int i=0; i<4; i++)
        {
            for (int j=0; j<4; j++)
            {
                buffer[k] = value.matrix[i][j];
                k++;
            }
        }
    }
    
    glUniformMatrix4fv(uniforms[uniform], 1, GL_FALSE, buffer);
}
