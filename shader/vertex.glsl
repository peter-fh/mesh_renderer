#version 410 core
layout (location = 0) in vec3 aPos;

uniform mat4 transform;

void main() {
	vec4 v = vec4(aPos.x, aPos.y, aPos.z ,1); 
	gl_Position = transform * v;
}

