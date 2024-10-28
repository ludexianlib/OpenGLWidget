#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
}

void Mesh::init()
{
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    // 位置坐标原点在中心 纹理坐标原点在左下
    std::vector<Vertex> v = {
       Vertex(Vec3D(-0.5f, -0.5f,  0.5f), Vec3D(0.1, 0, 0),   Vec2D(0, 0)),
       Vertex(Vec3D( 0.5f, -0.5f,  0.5f), Vec3D(0.1, 0, 0.5), Vec2D(1, 0)),
       Vertex(Vec3D( 0.5f,  0.5f,  0.5f), Vec3D(0.1, 0, 0),   Vec2D(1, 1)),
       Vertex(Vec3D( 0.5f,  0.5f,  0.5f), Vec3D(0.1, 0.2, 0), Vec2D(0, 0)),
       Vertex(Vec3D(-0.5f,  0.5f,  0.5f), Vec3D(0.1, 0, 0),   Vec2D(0, 0)),
       Vertex(Vec3D(-0.5f, -0.5f,  0.5f), Vec3D(0.1, 0, 0.3), Vec2D(0, 0)),
    };
    vertexes = v;
    indices = {
        0, 1, 2,
        3, 4, 5
    };

    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexes.size(), &vertexes[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * indices.size(), &indices[0], GL_STATIC_DRAW);


    // 位置 颜色 纹理
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texture));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::draw()
{
    m_shader->bind();
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}
