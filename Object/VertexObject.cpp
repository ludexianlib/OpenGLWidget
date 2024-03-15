#include <QDebug>
#include "VertexObject.h"

VertexObject::VertexObject()
{
	// ��ʼ��Opengl����
	initializeOpenGLFunctions();

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	float vertices[] = {
		// λ��				// ��ɫ
		 0.5f,  0.5f, 0.0f, 1, 0, 0,	// ����
		 0.5f, -0.5f, 0.0f, 0, 1, 0,	// ����
		-0.5f, -0.5f, 0.0f, 0, 0, 1,	// ����
		-0.5f,  0.5f, 0.0f, 0, 1, 0		// ����
	};
	uint indices[] = {
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
	};

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexObject::~VertexObject()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
}
