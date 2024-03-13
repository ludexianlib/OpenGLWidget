#include <QDebug>
#include "VertexObject.h"

VertexObject::VertexObject()
{
	// ��ʼ��Opengl����
	initializeOpenGLFunctions();

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	float vertices[] = {
		 0.5f,  0.5f, 0.0f,	// ���Ͻ�
		 0.5f, -0.5f, 0.0f,	// ���½�
		-0.5f, -0.5f, 0.0f,	// ���½�
		-0.5f,  0.5f, 0.0f	// ���Ͻ�
	};
	
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

VertexObject::~VertexObject()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
}
