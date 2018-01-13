#version 330

const int MAX_POINT_LIGHTS = 4;
const int MAX_SPOT_LIGHTS = 4;

in vec2 texCoord0;
in vec3 normal0;
in vec3 worldPos0;

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

struct Attenuation
{
    float constant;
    float linear;
    float exponent;
};

struct PointLight
{
    BaseLight bl;
    Attenuation atten;
    vec3 position;
    float range;
};

struct SpotLight
{
    PointLight pl;
    vec3 direction;
    float cutoff;
};

uniform vec3 baseColor;
uniform vec3 ambientLight;
uniform float specularIntensity;
uniform float specularExponent;
uniform sampler2D sampler;
uniform vec3 eyePos;

uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform SpotLight spotLights[MAX_SPOT_LIGHTS];

vec4 calcLight (BaseLight bl, vec3 dir, vec3 normal)
{
    float diffuseFactor = dot(normal, -dir);
    vec4 diffuseColor = vec4(0, 0, 0, 0);
    vec4 specColor = vec4(0, 0, 0, 0);
    
    if (diffuseFactor > 0)
    {
        diffuseColor = vec4(bl.color, 1.0) * bl.intensity * diffuseFactor;
        
        vec3 dirToEye = normalize(eyePos - worldPos0);
        vec3 reflectDir = normalize(reflect(dir, normal));
        
        float specFactor = dot(dirToEye, reflectDir);
        specFactor = pow(specFactor, specularExponent);
        
        if (specFactor > 0)
        {
            specColor = vec4(bl.color, 1.0) * specularIntensity * specFactor;
        }
    }

    return diffuseColor + specColor;
}

vec4 calcDirectionLight(DirectionalLight dl, vec3 normal)
{
    return calcLight(dl.baseLight, -dl.direction, normal);
}

vec4 calcPointLight(PointLight pl, vec3 normal)
{
    vec3 lightDirection = worldPos0 - pl.position;
    float distToPoint = length(lightDirection);
    
    if (distToPoint > pl.range)
        return vec4(0, 0, 0, 0);
    
    lightDirection = normalize(lightDirection);
    
    vec4 color = calcLight(pl.bl, lightDirection, normal);
    float atten = pl.atten.constant + pl.atten.linear*distToPoint + pl.atten.exponent*distToPoint*distToPoint + 0.0001;
    
    return color / atten;
}

vec4 calcSpotLight(SpotLight sl, vec3 normal)
{
    vec3 lightDirection = normalize(worldPos0 - sl.pl.position);
    float spotFactor = dot(lightDirection, sl.direction);
    
    vec4 color = vec4(0, 0, 0, 0);
    if (spotFactor > sl.cutoff)
    {
        color = calcPointLight(sl.pl, normal) * (1 - (1-spotFactor)/(1-sl.cutoff));
    }
    
    return color;
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
    
    for (int i=0; i<MAX_POINT_LIGHTS; i++)
        if (pointLights[i].bl.intensity > 0)
            totalLight += calcPointLight(pointLights[i], normal);

    for (int i=0; i<MAX_SPOT_LIGHTS; i++)
        if (spotLights[i].pl.bl.intensity > 0)
            totalLight += calcSpotLight(spotLights[i], normal);

    fragColor = color * totalLight;
}
