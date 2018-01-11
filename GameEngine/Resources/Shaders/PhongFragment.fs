#version 330

in vec2 texCoord0;
out vec4 fragColor;

uniform vec3 baseColor;
uniform vec3 ambientLight;
uniform sampler2D sampler;

void main()
{
    vec4 totalLight = vec4(ambientLight, 1);
    
    vec4 texColor = texture(sampler, texCoord0.xy);
    vec4 color = vec4(baseColor, 1);
    if (texColor != vec4(0, 0, 0, 1))
        color *= texColor;
    
    fragColor = color * totalLight;
}
