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

#endif /* Shader_hpp */

class Shader
{
private:
    GLuint program;
public:
    Shader();
    
    void AddVertexShader(std::string text);
    void AddGeometryShader(std::string text);
    void AddFragmentShader(std::string text);
    void AddProgram(std::string text, int type);
    void CompileShader();
    void Bind();
};
