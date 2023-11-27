#include "OpenGLObject.h"

OpenGLObject::OpenGLObject()
{
	initializeOpenGLFunctions();

	// 生成顶点缓冲对象和顶点缓冲数组
	glGenBuffers(1, &mVBO);
	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mEBO);
}

OpenGLObject::~OpenGLObject()
{
	glDeleteVertexArrays(1, &mVAO);
	glDeleteBuffers(1, &mVBO);
	glDeleteBuffers(1, &mEBO);
}

void OpenGLObject::updateBufferData(float vertex[], int vertexCount, float index[], int indexCount)
{
	// 绑定顶点缓冲对象的缓冲类型
	glBindVertexArray(mVAO);

	// 将用户定义的数据复制到当前绑定缓冲的函数
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexCount, vertex, GL_STATIC_DRAW);

	// 更新顶点索引，避免使用重复顶点
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indexCount, index, GL_STATIC_DRAW);

	// 如何解析顶点数据
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	// 启用顶点属性
	glEnableVertexAttribArray(0);

	// 取消绑定
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
