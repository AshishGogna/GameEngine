//
//  Transform.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 04/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Transform.hpp"
#include "Util.hpp"
#include "Window.hpp"

Transform::Transform()
{
    position = Vector3().Zero();
    rotation = Vector3().Zero();
    scale = Vector3().One();

    up = Vector3().Up();
    forward = Vector3().Forward();
    right = Vector3().Right();

    UpdateDirections();
}

void Transform::Translate(Vector3 by)
{
    position = position + by;
}

void Transform::Rotate(float angle, Vector3 axis)
{
    axis = axis.Normalized() * angle;
    rotation = rotation + axis;

    Vector3 view = forward;
    view = view.Rotate(angle, Vector3().Up() * axis.y).Normalized();
    
    Vector3 hAxis = (up * axis.x).Cross(view).Normalized();
    view = view.Rotate(angle, hAxis).Normalized();
    
    forward = view;
    up = forward.Cross(hAxis).Normalized();
    
    Util::Print(up.ToString());
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
    
    //up = rotationMatrix * up;
    //forward = rotation * forward;
    
    return  translationMatrix * rotationMatrix * scaleMatrix;
}

void Transform::UpdateDirections()
{
}
