#version 400 core

#define PI 3.141592653589793238462643383279

in vec3 pass_position;
in vec2 pass_texCoord;

out vec4 out_Color;

uniform sampler2D textureSampler;

void main() {
    vec2 longitudeLatitude = vec2((atan(pass_position.y, pass_position.x) / PI + 1.0) * 0.5,
                                  (asin(pass_position.z) / PI + 0.5));

    out_Color = texture2D(textureSampler, longitudeLatitude);
}
