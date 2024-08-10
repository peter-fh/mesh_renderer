#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h> // include glad to get all the required OpenGL headers
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
  

class Shader
{
public:
    unsigned int id;
  
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    void use();

    GLint get(const std::string& name);
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
};
  
#endif
