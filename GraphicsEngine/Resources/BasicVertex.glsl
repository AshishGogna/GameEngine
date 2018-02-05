#version 330 core

layout(location = 0) in vec3 position;

uniform mat4 transform;

out vec4 color;

void main()
{
    color = vec4(clamp(position, 0.0, 1.0), 1.0);
    gl_Position = transform * vec4(position, 1.0);
}
