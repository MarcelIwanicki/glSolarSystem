#version 400 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

out vec3 pass_position;
out vec2 pass_texCoord;
out vec3 surfaceNormal;
out vec3 toLight;
out vec3 toCamera;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
uniform vec3 lightPosition;

void main(void) {

    vec4 worldPosition = transform * vec4(position, 1.0);

    gl_Position = projection * view * worldPosition;
    pass_texCoord = texCoord;
    pass_position = position;

    surfaceNormal = (transform * vec4(normal, 0.0)).xyz;
    toLight = lightPosition - worldPosition.xyz;
    toCamera = (inverse(view) * vec4(0.0, 0.0, 0.0, 1.0)).xyz - worldPosition.xyz;

}
