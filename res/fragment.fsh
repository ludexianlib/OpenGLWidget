#version 330 core

out vec4 FragColor;

uniform vec4 outColor;	// 全局变量

void main() 
{
    FragColor = outColor;
}
