//
//  Texture.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <GL/glew.h>
#include <iostream>

class Texture
{
private:
    GLuint id;
    void Init(GLuint id);
    GLuint LoadTexture(std::string filePath);
    
public:
    Texture();
    Texture(GLuint id);
    Texture(std::string filePath);
    
    void Bind();
    GLuint GetId();
};

#endif /* Texture_hpp */
