#version 330 core

// Interpolated color data from the vertex shader.
in vec2 TexCoord;

// Output data
out vec4 color;

uniform sampler2D texture1;

// Main function
void main(){
    // Set the output color of our current pixel
    color = texture(texture1, TexCoord);
}
