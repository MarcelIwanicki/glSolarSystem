#version 400 core

#define PI 3.141592653589793238462643383279

in vec3 pass_position;
in vec2 pass_texCoord;
in vec3 surfaceNormal;
in vec3 toLight;
in vec3 toCamera;

out vec4 out_Color;

uniform sampler2D textureSampler;
uniform vec3 lightColor;
uniform float shineDamper;
uniform float reflectivity;

void main(void) {

    vec2 longitudeLatitude = vec2((atan(pass_position.y, pass_position.x) / PI + 1.0) * 0.5,
                                  (asin(pass_position.z) / PI + 0.5));

    vec3 unitNormal = normalize(surfaceNormal);
    vec3 unitLightVector = normalize(toLight);

    float nDot1 = dot(unitNormal, unitLightVector);
    float brightness = max(nDot1, 0.07);
    vec3 diffuse = brightness * lightColor;

    vec3 unitToCamera = normalize(toCamera);
    vec3 lightDirection = -unitLightVector;
    vec3 reflectedLightDirection = reflect(lightDirection, unitNormal);

    float specularFactor = dot(reflectedLightDirection, unitToCamera);
    specularFactor = max(specularFactor, 0.0);
    float dampedFactor = pow(specularFactor, shineDamper);
    vec3 finalSpecular = dampedFactor * reflectivity * lightColor;

    out_Color = vec4(diffuse, 1.0) * texture(textureSampler, longitudeLatitude) + vec4(finalSpecular, 1.0);

}
