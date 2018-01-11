//
//  Texture.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Texture.hpp"

Texture::Texture()
{
    
}

Texture::Texture(GLuint id)
{
    this->id = id;
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, id);
}

GLuint Texture::GetId()
{
    return id;
}
