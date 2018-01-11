#version 330

in vec2 texCoord0;
in vec3 normal0;

out vec4 fragColor;

struct BaseLight
{
    vec3 color;
    float intensity;
};

struct DirectionalLight
{
    BaseLight baseLight;
    vec3 direction;
};

uniform vec3 baseColor;
uniform vec3 ambientLight;
uniform sampler2D sampler;
uniform DirectionalLight directionalLight;

vec4 calcLight (BaseLight bl, vec3 dir, vec3 normal)
{
    float diffuseFactor = dot(normal, -dir);
    vec4 diffuseColor = vec4(0, 0, 0, 0);
    if (diffuseFactor > 0)
        diffuseColor = vec4(bl.color, 1.0) * bl.intensity * diffuseFactor;
    
    return diffuseColor;
}

vec4 calcDirectionLight(DirectionalLight dl, vec3 normal)
{
    return calcLight(dl.baseLight, -dl.direction, normal);
}

void main()
{
    vec4 totalLight = vec4(ambientLight, 1);
    
    vec4 texColor = texture(sampler, texCoord0.xy);
    vec4 color = vec4(baseColor, 1);
    if (texColor != vec4(0, 0, 0, 1))
        color *= texColor;
    
    vec3 normal = normalize(normal0);
    totalLight += calcDirectionLight(directionalLight, normal);
    
    fragColor = color * totalLight;
}
