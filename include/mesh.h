#ifndef MESH_H
#define MESH_H

#include "glm/glm.hpp"
#include <string>
#include "shader.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
};


class Mesh {
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

    std::vector<Vertex>         vertices;
    std::vector<unsigned int>   indices;

    void Draw(Shader& shader);

private:
    unsigned int VAO, VBO, EBO;
    void setup_mesh();
};

#endif
