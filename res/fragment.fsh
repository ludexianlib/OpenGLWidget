#version 330 core

in vec2 textureCoord;

// ¡Ω’≈Õº∆¨Œ∆¿Ì
uniform sampler2D outTexture;
uniform sampler2D smileTexture;

out vec4 FragColor;

void main() 
{
    FragColor = mix(texture(outTexture, textureCoord), texture(smileTexture, textureCoord), 0.2);
}
