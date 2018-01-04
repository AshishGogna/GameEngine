#version 330 core

layout(location = 0) in vec3 position;

out vec4 color;
uniform float uf;

void main()
{
    color = vec4(clamp(position, 0.0, uf), 1.0);
    gl_Position = vec4(position, 1.0);
}