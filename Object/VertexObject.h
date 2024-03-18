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
	uint m_VAO;
	uint m_VBO;
	uint m_EBO;
};