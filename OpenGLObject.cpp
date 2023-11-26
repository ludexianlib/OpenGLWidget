#include "OpenGLObject.h"

OpenGLObject::OpenGLObject()
{
	initializeOpenGLFunctions();

	// ���ɶ��㻺�����Ͷ��㻺������
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
	// �󶨶��㻺�����Ļ�������
	glBindVertexArray(mVAO);
	glBindBuffer(GL_ARRAY_BUFFER, mVBO);

	// ���û���������ݸ��Ƶ���ǰ�󶨻���ĺ���
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * length, vertex, GL_STATIC_DRAW);

	// ��ν�����������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	// ���ö�������
	glEnableVertexAttribArray(0);

	// ȡ����
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
