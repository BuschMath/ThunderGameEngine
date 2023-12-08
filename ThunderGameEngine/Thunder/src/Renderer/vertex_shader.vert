#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace; // The vertex position
layout(location = 1) in vec3 vertexColor; // The vertex color

// Output data; will be interpolated for each fragment.
out vec3 fragmentColor;

// Main function, which transforms vertex positions to clip coordinates.
void main(){
    gl_Position = vec4(vertexPosition_modelspace, 1.0);
    fragmentColor = vertexColor; // Pass the color to the fragment shader
}
