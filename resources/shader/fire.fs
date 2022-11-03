#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// NOTE: Add here your custom variables

#define     MAX_LIGHTS              4
#define     LIGHT_DIRECTIONAL       0
#define     LIGHT_POINT             1

struct MaterialProperty {
    vec3 color;
    int useSampler;
    sampler2D sampler;
};

struct Light {
    int enabled;
    int type;
    vec3 position;
    vec3 target;
    vec4 color;
};

// Input lighting values
uniform Light lights[MAX_LIGHTS];
uniform vec4 ambient;
uniform vec3 viewPos = vec3(10.0, 20.0, 12.0);

void main()
{
    // Texel color fetching from texture sampler
    vec4 texelColor = texture(texture0, fragTexCoord);
    vec3 normal = normalize(fragNormal);
    vec3 view3D = normalize(viewPos - fragPosition);
    
    float d = dot(view3D, normal);

    finalColor = texelColor;

    // if (d > -0.7)
        finalColor = pow(finalColor, vec4(1 / (1 + d)));
        // finalColor = vec4(1.0, .88, .35, 1);
        // finalColor = vec4(.89, .45, .16, 1);

    // finalColor = vec4(normal, 1);
    // Gamma correction
    // finalColor = vec4(d, d, d, 1);
    finalColor = pow(finalColor, vec4(2.2));
}