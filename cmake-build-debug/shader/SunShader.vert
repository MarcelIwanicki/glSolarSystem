#version 400 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec3 pass_position;
out vec2 pass_texCoord;

uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;

void main() {
    vec4 worldPosition = transform * vec4(position, 1.0);

    gl_Position = projection * view * worldPosition;
    pass_texCoord = texCoord;
    pass_position = position;
}
