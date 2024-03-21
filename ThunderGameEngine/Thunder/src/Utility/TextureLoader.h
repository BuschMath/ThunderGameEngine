// TextureLoader.h
#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <gl/glew.h> // Include glad to get the required OpenGL headers
#include <string>

class TextureLoader {
public:
    static GLuint LoadTexture(const char* filepath);
};

#endif // TEXTURELOADER_H
