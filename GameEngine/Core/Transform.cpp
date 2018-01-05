//
//  Transform.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 05/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Transform.hpp"

Transform::Transform()
{
    translation = Vector3(0, 0, 0);
    rotation = Vector3(0, 0, 0);
    scale = Vector3(1, 1, 1);
}

Matrix4 Transform::GetTransformation()
{
    Matrix4 translationMatrix = Matrix4().InitTranslation(translation.x, translation.y, translation.z);
    Matrix4 rotationMatrix = Matrix4().InitRotation(rotation.x, rotation.y, rotation.z);
    Matrix4 scaleMatrix = Matrix4().InitScale(scale.x, scale.y, scale.z);
    
    return translationMatrix.Multiply(rotationMatrix.Multiply(scaleMatrix));
}

void Transform::SetTranslation(float x, float y, float z)
{
    translation = Vector3(x, y, z);
}

void Transform::SetRotation(float x, float y, float z)
{
    rotation = Vector3(x, y, z);
}

void Transform::SetScale(float x, float y, float z)
{
    scale = Vector3(x, y, z);
}
