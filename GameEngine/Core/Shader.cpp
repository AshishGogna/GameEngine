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
    
    /*
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
     */
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
    
    
    //glDetachShader(program, VertexShaderID);
    //glDetachShader(program, FragmentShaderID);
    
    //glDeleteShader(VertexShaderID);
    //glDeleteShader(FragmentShaderID);

    /*
    GLint result = GL_FALSE;
    
    glLinkProgram(program); //Link and check
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    if (result == 0)
    {
        int infoLog;
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
    */
}

void Shader::Bind()
{
    glUseProgram(program);
}
