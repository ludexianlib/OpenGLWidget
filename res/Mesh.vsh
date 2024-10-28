#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 1) in vec2 aTexture;

out vec4 vertexColor;
out vec2 vertexTexture;

void main()
{
    gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);
    vertexColor = vec4(aColor, 1.0);
    vertexTexture = aTexture;
}