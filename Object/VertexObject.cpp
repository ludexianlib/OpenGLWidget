#include <QDebug>
#include "VertexObject.h"

VertexObject::VertexObject()
{
	// 初始化Opengl函数
	initializeOpenGLFunctions();

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	float vertices[] = {
		// 位置			  // 颜色
		 0.0,  0.5, 0.0f, 1, 0, 0,
		-0.5, -0.5, 0.0f, 0, 0, 1,
		 0.0, -0.5, 0.0f, 0, 1, 0,
	};

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
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
