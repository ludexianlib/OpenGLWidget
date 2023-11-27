#include "OpenGLObject.h"

OpenGLObject::OpenGLObject()
{
	initializeOpenGLFunctions();

	// ���ɶ��㻺�����Ͷ��㻺������
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
	// �󶨶��㻺�����Ļ�������
	glBindVertexArray(mVAO);

	// ���û���������ݸ��Ƶ���ǰ�󶨻���ĺ���
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexCount, vertex, GL_STATIC_DRAW);

	// ���¶�������������ʹ���ظ�����
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indexCount, index, GL_STATIC_DRAW);

	// ��ν�����������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	// ���ö�������
	glEnableVertexAttribArray(0);

	// ȡ����
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
