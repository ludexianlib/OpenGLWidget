#version 330 core

in vec4 vertexColor;
in vec2 vertexTexture;
out vec4 fragColor;

// ����ͼƬ
uniform sampler2D fragTextuer;

void main()
{
    fragColor = texture(fragTextuer, vertexTexture);
}