#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace; // The vertex position
layout(location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 MVP; // ModelViewProjection matrix

// Main function, which transforms vertex positions to clip coordinates.
void main(){
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1.0);
    TexCoord = aTexCoord; // Pass the color to the fragment shader
}
