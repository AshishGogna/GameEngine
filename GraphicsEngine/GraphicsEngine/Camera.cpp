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
    
    transform.position = Vector3(1.0f, 1.0f, -5.0f);
    //transform.forward = Vector3(-0.45f, 0.0f, 1.0f);
}

Matrix4 Camera::GetMvpMatrix(vector<Mesh> meshes)
{
    Matrix4 transformationMatrix = meshes[0].transform.GetTransformationMatrix();
    for (int i=1; i<meshes.size(); i++)
        transformationMatrix = transformationMatrix * meshes[i].transform.GetTransformationMatrix();
    
    Matrix4 projectionMatrix = Matrix4().ProjectionMatrix(fov, Window::GetWidth(), Window::GetHeight(), zNear, zFar);

    //Matrix4 cameraTrans = Matrix4().TranslationMatrix(transform.position);
    Matrix4 cameraMatrix = Matrix4().CameraMatrix(transform.position, transform.forward, transform.up);

    return projectionMatrix * cameraMatrix * transformationMatrix;
    //return projectionMatrix.Multiply(cameraRotation.Multiply(cameraTranslation.Multiply(transformationMatrix)));
}

void Camera::Update()
{
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_LEFT) == 1)
    {
        //transform.Translate(Vector3(0.01, 0, 0));
        transform.Rotate(1, Vector3(1, 0, 0));
    }
}
