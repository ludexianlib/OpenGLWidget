#include "PanelObject.h"

void PanelObject::init()
{
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);

    // 位置坐标原点在中心 纹理坐标原点在左下
    std::vector<Vertex> v = {
       Vertex(Vec3D(-0.5f, -0.5f,  0.5f), Vec3D(0.1, 0, 0)),
       Vertex(Vec3D( 0.5f, -0.5f,  0.5f), Vec3D(0.1, 0, 0)),
       Vertex(Vec3D( 0.5f,  0.5f,  0.5f), Vec3D(0.1, 0, 0)),
       Vertex(Vec3D( 0.5f,  0.5f,  0.5f), Vec3D(0.1, 0, 0)),
       Vertex(Vec3D(-0.5f,  0.5f,  0.5f), Vec3D(0.1, 0, 0)),
       Vertex(Vec3D(-0.5f, -0.5f,  0.5f), Vec3D(0.1, 0, 0)),
    };
    m_mesh.vertexes = v;

    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_mesh.vertexes.size(), &m_mesh.vertexes[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);
#if 0
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texture));
    glEnableVertexAttribArray(2);
#endif

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void PanelObject::draw()
{
    glBindVertexArray(m_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
