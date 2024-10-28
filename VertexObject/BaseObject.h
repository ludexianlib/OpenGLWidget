#pragma once
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Core>
#include "Vertexes.h"

class BaseObject : public QOpenGLFunctions_3_3_Core
{
public:
	BaseObject();
	virtual ~BaseObject();

	virtual void init() = 0;	// 初始化
	virtual void draw() = 0;	// 绘制

	// 着色器
	virtual bool compileShader(const QString& vertexFile, const QString& fragmentFile);
	virtual bool compileShader(const char* vertexSource, const char* fragmentSource);
	
protected:
	GLuint m_VAO = 0;	// 顶点数组对象
	GLuint m_VBO = 0;	// 顶点缓冲对象
	GLuint m_EBO = 0;	// 索引缓冲对象

	QOpenGLShaderProgram* m_shader = nullptr; // 着色器
};
