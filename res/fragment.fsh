#version 330 core

out vec4 FragColor;

// 光照颜色 物体颜色
uniform vec3 objectColor;
uniform vec3 lightColor;

// 光源位置
uniform vec3 lightPos;

// 漫反射法向量 物体位置
in vec3 Normal;
in vec3 FragPos;

// 镜面反射 观察（相机）位置
uniform vec3 viewPos;

void main() 
{
    // 环境光照
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // 漫反射
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);  // 光的方向向量是光源位置向量与片段位置向量之间的向量差
    float diff = max(dot(norm, lightDir), 0.0);     // 两个向量如果大于90度为负数 取0
    vec3 diffuse = diff * lightColor;

    // 镜面反射
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos); // 观察向量
    vec3 reflectDir = reflect(-lightDir, norm);  // 第一个参数是从光源指向片段位置的向量，对lightDir取反即可
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}
