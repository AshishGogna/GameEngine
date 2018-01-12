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
#include "BaseLight.hpp"
#include "DirectionalLight.hpp"
#include "Transform.hpp"

class PhongShader : public Shader
{
private:
    Transform trns;
public:
    Vector3 ambientLight;
    DirectionalLight directionalLight;
    
    PhongShader();
    PhongShader(Transform t);
    void UpdateUniform(Matrix4 worldMatrix, Matrix4 projectedMatrix, Material material);
    void SetUniformBaseLight(std::string uniform, BaseLight bl);
    void SetUniformDirectionalLight(std::string uniform, DirectionalLight dl);
};

#endif /* PhongShader_hpp */
