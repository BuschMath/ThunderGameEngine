#version 330 core

// Interpolated color data from the vertex shader.
in vec3 fragmentColor;

// Output data
out vec4 color;

// Main function
void main(){
    // Set the output color of our current pixel
    color = vec4(fragmentColor, 1.0);
}
