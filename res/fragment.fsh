#version 330 core

out vec4 FragColor;

// ������ɫ ������ɫ
uniform vec3 objectColor;
uniform vec3 lightColor;

// ��Դλ��
uniform vec3 lightPos;

// �����䷨���� ����λ��
in vec3 Normal;
in vec3 FragPos;

void main() 
{
    // ��������
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // ������
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);  // ��ķ��������ǹ�Դλ��������Ƭ��λ������֮���������
    float diff = max(dot(norm, lightDir), 0.0);     // ���������������90��Ϊ���� ȡ0
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result, 1.0);
}
