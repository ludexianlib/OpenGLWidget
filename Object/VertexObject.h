#pragma once
#include <QObject>
#include <QOpenGLFunctions_3_3_Core>

/*
 * ���㻺����������
 * ��Ҫ�̳�QOpenGLFunctions_3_3_Core����ʹ��opengl�����ӿ�
 */
class VertexObject : public QOpenGLFunctions_3_3_Core
{
public:
	VertexObject();
	~VertexObject();

	void drawObject();
public:
	uint m_VAO = 0;
	uint m_VBO = 0;
	uint m_EBO = 0;
};