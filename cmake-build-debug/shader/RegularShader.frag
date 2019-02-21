#version 400 core

in vec2 pass_texCoord;

out vec4 out_Color;

uniform sampler2D textureSampler;

void main() {
    out_Color = texture2D(textureSampler, pass_texCoord);
}