#version 330 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 _uv;

out vec2 uv;

uniform mat4 model;
uniform mat4 proj;

void main(){
    gl_Position = proj * model * vec4(pos, 1.0);
    uv = _uv;
};
