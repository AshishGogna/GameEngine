//
//  PhongShader.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 11/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef PhongShader_hpp
#define PhongShader_hpp

#include <stdio.h>

#include "Shader.hpp"
#include "Material.hpp"

class PhongShader : public Shader
{
public:
    Vector3 AmbientLight;
    PhongShader();
    void UpdateUniform(Matrix4 worldMatrix, Matrix4 projectedMatrix, Material material);
};

#endif /* PhongShader_hpp */
