//
//  Transform.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 04/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Transform.hpp"
#include "Util.hpp"

Transform::Transform()
{
    position = Vector3().Zero();
    rotation = Vector3().Zero();
    scale = Vector3().One();
}

void Transform::Translate(Vector3 by)
{
    position = position + by;
}

void Transform::Rotate(Vector3 by)
{
    rotation = rotation + by;
}

void Transform::Scale(Vector3 by)
{
    scale = scale * by;
}

Matrix4 Transform::GetTransformationMatrix()
{
    Matrix4 translationMatrix = Matrix4().TranslationMatrix(position);
    Matrix4 rotationMatrix = Matrix4().RotationMatrix(rotation);
    Matrix4 scaleMatrix = Matrix4().ScaleMatrix(scale);
    
    return  translationMatrix * rotationMatrix * scaleMatrix;
}
