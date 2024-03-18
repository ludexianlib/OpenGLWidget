#pragma once
#include <QObject>
#include <QOpenGLFunctions_3_3_Core>

/*
 * 顶点缓冲对象管理类
 * 需要继承QOpenGLFunctions_3_3_Core才能使用opengl函数接口
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