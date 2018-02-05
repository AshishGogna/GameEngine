//
//  Shader.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Shader.hpp"
#include "Util.hpp"
#include <fstream>
#include <vector>
#include "Util.hpp"
#include "Window.hpp"

Shader::Shader()
{
    Init();
}

Shader::Shader(string vertexShaderPath, string fragmentShaderPath)
{
    Init();
    
    AddProgram(LoadShader(vertexShaderPath), GL_VERTEX_SHADER);
    AddProgram(LoadShader(fragmentShaderPath), GL_FRAGMENT_SHADER);
    
    CompileShader();
}

void Shader::Init()
{
    if (!Window::isInitialized()) return;

    program = glCreateProgram();
    if (program == 0)
    {
        Util::ExitWithError("Shader program creation failed.");
    }
}

void Shader::AddProgram(string shaderCode, int type)
{
    GLuint VertexShaderID = glCreateShader(type);
    
    GLint Result = GL_FALSE;
    int InfoLogLength;
    
    char const * VertexSourcePointer = shaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);
    
    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 )
    {
        vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        Util::Print(&VertexShaderErrorMessage[0]);
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
    //BindShader
    glUseProgram(program);
}

string Shader::LoadShader(string filePath)
{
    std::string shaderCode;
    
    std::ifstream shaderStream;
    shaderStream.open(filePath.c_str(), std::ios::in);
    if(shaderStream.is_open())
    {
        std::string line = "";
        while(getline(shaderStream, line))
        {
            shaderCode += "\n" + line;
        }
        shaderStream.close();
    }
    else
    {
        Util::ExitWithError("Unable to open " + filePath);
    }
    
    return shaderCode;
}


void Shader::AddUiform(string name)
{
    GLint uniformLocation = glGetUniformLocation(program, name.c_str());

    if (uniformLocation == 0xFFFFFFFF)
        Util::ExitWithError("Could not find uniform :" + name);
    
    uniforms[name] = uniformLocation;
}

void Shader::SetUniform(std::string name, Matrix4 value)
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
                buffer[k] = value.mat[i][j];
                k++;
            }
        }
    }
    
    glUniformMatrix4fv(uniforms[name], 1, GL_TRUE, buffer);
}
