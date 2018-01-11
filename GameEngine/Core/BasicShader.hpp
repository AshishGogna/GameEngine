//
//  BasicShader.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef BasicShader_hpp
#define BasicShader_hpp

#include <stdio.h>
#include "Shader.hpp"
#include "Material.hpp"

class BasicShader : public Shader
{
public:
    BasicShader();
    void UpdateUniform(Matrix4 worldMatrix, Matrix4 projectedMatrix, Material material);
};

#endif /* BasicShader_hpp */
