#include "BaseObject.h"

BaseObject::BaseObject() : QOpenGLFunctions_3_3_Core()
{
	initializeOpenGLFunctions();

	// 创建着色器对象
	m_shader = new QOpenGLShaderProgram();
}

BaseObject::~BaseObject()
{
	delete m_shader;
}

bool BaseObject::compileShader(const QString& vertexFile, const QString& fragmentFile)
{
	bool ret1 = m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexFile);
	bool ret2 = m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentFile);
	bool ret3 = m_shader->link();
	return ret1 && ret2 && ret3;
}

bool BaseObject::compileShader(const char* vertexSource, const char* fragmentSource)
{
	bool ret1 = m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexSource);
	bool ret2 = m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentSource);
	bool ret3 = m_shader->link();
	return ret1 && ret2 && ret3;
}
