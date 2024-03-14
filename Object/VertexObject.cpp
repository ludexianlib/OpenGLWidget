#include <QDebug>
#include "VertexObject.h"

VertexObject::VertexObject()
{
	// 初始化Opengl函数
	initializeOpenGLFunctions();

	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	float vertices[] = {
		// 位置              // 颜色
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // 右下
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // 左下
		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // 顶部
	};
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// 颜色属性
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
