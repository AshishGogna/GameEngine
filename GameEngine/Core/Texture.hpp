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

class Texture
{
private:
    GLuint id;
    
public:
    
    Texture();
    Texture(GLuint id);
    
    void Bind();
    GLuint GetId();
};

#endif /* Texture_hpp */
