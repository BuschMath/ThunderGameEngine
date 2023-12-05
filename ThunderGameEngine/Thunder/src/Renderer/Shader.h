#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void Use() const;
    GLuint GetProgram() const;

private:
    GLuint program;
    std::string ReadShaderFile(const char* shaderPath);
    void CompileAndLink(const char* vertexCode, const char* fragmentCode);
};

#endif // SHADER_H

