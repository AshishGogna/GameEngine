//
//  Camera.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 10/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Camera.hpp"
#include "Window.hpp"
#include "Time.hpp"
#include <GLFW/glfw3.h>

Camera::Camera()
{
    Init(Vector3(0, 0, 0), Vector3(0, 0, 1), Vector3(0, 1, 0));
}

Camera::Camera(Vector3 position, Vector3 forward, Vector3 up)
{
    Init(position, forward, up);
}

void Camera::Init(Vector3 pos, Vector3 fwd, Vector3 u)
{
    //pos.x = 3;
    position = pos;
    forward = fwd;
    up = u;
    
    forward.Normalize();
    up.Normalize();
}

void Camera::Input()
{
    float mov = (10 * Time::delta);
    float rot = (100 * Time::delta);
    
    //Mvmt
    if (glfwGetKey(Window::window, GLFW_KEY_W) == 1) {
        Move(forward, mov);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_S) == 1) {
        Move(forward, -mov);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_A) == 1) {
        Move(GetLeft(), mov);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_D) == 1) {
        Move(GetRight(), mov);
    }
    
    //Rot
    if (glfwGetKey(Window::window, GLFW_KEY_UP) == 1) {
        RotateX(-rot);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_DOWN) == 1) {
        RotateX(rot);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_LEFT) == 1) {
        RotateY(-rot);
    }
    if (glfwGetKey(Window::window, GLFW_KEY_RIGHT) == 1) {
        RotateY(rot);
    }
}

void Camera::Move(Vector3 direction, float amount)
{
    position = position.Add(direction.Multiply(amount));
}

void Camera::RotateX(float angle)
{
    Vector3 horAxis = yAxis.Cross(forward);
    horAxis.Normalize();
    
    forward.Rotate(angle, horAxis);
    forward.Normalize();
    
    up = forward.Cross(horAxis);
    up.Normalize();
}

void Camera::RotateY(float angle)
{
    Vector3 horAxis = yAxis.Cross(forward);
    horAxis.Normalize();

    forward.Rotate(angle, yAxis);
    forward.Normalize();
    
    up = forward.Cross(horAxis);
    up.Normalize();
}

Vector3 Camera::GetLeft()
{
    Vector3 left = forward.Cross(up);
    left.Normalize();
    
    return left;
}

Vector3 Camera::GetRight()
{
    Vector3 right = up.Cross(forward);
    right.Normalize();
    
    return right;
}
