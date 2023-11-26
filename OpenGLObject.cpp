#include "OpenGLObject.h"

OpenGLObject::OpenGLObject()
{
	initializeOpenGLFunctions();

	// 生成顶点缓冲对象和顶点缓冲数组
	glGenBuffers(1, &mVBO);
	glGenVertexArrays(1, &mVAO);
}

OpenGLObject::~OpenGLObject()
{
	glDeleteVertexArrays(1, &mVAO);
	glDeleteBuffers(1, &mVBO);
}

void OpenGLObject::updateBufferData(float vertex[], int length)
{
	// 绑定顶点缓冲对象的缓冲类型
	glBindVertexArray(mVAO);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);

	// 将用户定义的数据复制到当前绑定缓冲的函数
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * length, vertex, GL_STATIC_DRAW);

	// 如何解析顶点数据
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	// 启用顶点属性
	glEnableVertexAttribArray(0);

	// 取消绑定
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
