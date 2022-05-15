#version 330 core

out vec4 FragColor;

in vec2 uv;

uniform sampler2D tex;

void main(){
    FragColor = vec4(0.75f, 0.25f, 1.0f, 0.1f);
};
