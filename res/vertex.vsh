#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexture;

out vec2 textureCoord;

// �ⲿ����任����
uniform mat4 transform;

void main() 
{
	gl_Position = transform * vec4(aPos, 1.0);
	textureCoord = aTexture;
}
