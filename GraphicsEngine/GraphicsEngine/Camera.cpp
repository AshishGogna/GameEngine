//
//  Camera.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 05/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Camera.hpp"
#include "Window.hpp"
#include "Util.hpp"

Camera::Camera()
{
    
}

Camera::Camera(float fov, float zNear, float zFar)
{
    this->fov = fov;
    this->zNear = zNear;
    this->zFar = zFar;
}

Matrix4 Camera::GetMvpMatrix(vector<Mesh> meshes)
{
    Matrix4 transformationMatrix;
    for (int i=0; i<meshes.size(); i++)
        transformationMatrix = meshes[i].transform.GetTransformationMatrix();
    
    Matrix4 projectionMatrix = Matrix4().ProjectionMatrix(fov, Window::GetWidth(), Window::GetHeight(), zNear, zFar);

    Matrix4 cameraMatrix = Matrix4().CameraMatrix(transform.position, transform.forward, transform.up);

    return projectionMatrix * cameraMatrix * transformationMatrix;
    //return projectionMatrix.Multiply(cameraRotation.Multiply(cameraTranslation.Multiply(transformationMatrix)));
}
