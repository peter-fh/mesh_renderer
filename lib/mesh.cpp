#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices){
	this->vertices = vertices;
	this->indices = indices;

	setup_mesh();
}

void Mesh::setup_mesh(){
}
