#include "OpenGLWidgetPrivate.h"

OpenGLWidgetPrivate::OpenGLWidgetPrivate()
{
	m_shader = QSharedPointer<QOpenGLShaderProgram>(new QOpenGLShaderProgram);
	m_lightShader = QSharedPointer<QOpenGLShaderProgram>(new QOpenGLShaderProgram);
	m_vertexObj = QSharedPointer<VertexObject>(new VertexObject);
	m_textureObj = QSharedPointer<TextureObject>(new TextureObject);
	m_lightObj = QSharedPointer<LightObject>(new LightObject);
}

OpenGLWidgetPrivate::~OpenGLWidgetPrivate()
{
}
