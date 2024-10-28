#pragma once
#include <QOpenGLFunctions_3_3_Core>
#include "Vertexes.h"

class BaseObject : public QOpenGLFunctions_3_3_Core
{
public:
	BaseObject();
	virtual ~BaseObject();

	virtual void init() = 0;	// ��ʼ��
	virtual void draw() = 0;	// ����
	
protected:
	Mesh m_mesh;		// �������

	GLuint m_VAO = 0;	// �����������
	GLuint m_VBO = 0;	// ���㻺�����
	GLuint m_EBO = 0;	// �����������
};
