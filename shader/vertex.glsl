#version 410 core
layout (location = 0) in vec3 aPos;

void main() {
	vec4 v = vec4(aPos.x, aPos.y, aPos.z ,1); 
	gl_Position = v;
}

