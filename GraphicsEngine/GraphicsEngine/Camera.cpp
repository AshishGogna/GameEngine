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
    
    mvmtStep = 0.1f;
    rotStep = 1.0f;
    //transform.position = Vector3(1.0f, 1.0f, -5.0f);
    //transform.forward = Vector3(-0.45f, 0.0f, 1.0f);
}

Matrix4 Camera::GetMvpMatrix(vector<Mesh> meshes)
{
    Matrix4 transformationMatrix = meshes[0].transform.GetTransformationMatrix();
    Matrix4 projectionMatrix = Matrix4().ProjectionMatrix(fov, Window::GetWidth(), Window::GetHeight(), zNear, zFar);
    Matrix4 cameraMatrix = Matrix4().CameraMatrix(transform.position, transform.forward, transform.up);

    Matrix4 mvp = projectionMatrix * cameraMatrix * transformationMatrix;
    for (int i=1; i<meshes.size(); i++)
        mvp = mvp * meshes[i].transform.GetTransformationMatrix();

    return mvp;
}

void Camera::Update()
{
    //Movement: WASD
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_A) == 1)
        transform.Translate(transform.right * -mvmtStep);
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_D) == 1)
        transform.Translate(transform.right * mvmtStep);
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_W) == 1)
        transform.Translate(transform.forward * mvmtStep);
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_S) == 1)
        transform.Translate(transform.forward * -mvmtStep);
    
    //Rotation: Arrow keys
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_LEFT) == 1)
        transform.Rotate(-rotStep, Vector3().Up());
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_RIGHT) == 1)
        transform.Rotate(rotStep, Vector3().Up());
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_UP) == 1)
        transform.Rotate(-rotStep, Vector3().Right());
    if (glfwGetKey(Window::GetWindow(), GLFW_KEY_DOWN) == 1)
        transform.Rotate(rotStep, Vector3().Right());
}
