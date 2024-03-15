#include "OpenGLWidgetPrivate.h"

OpenGLWidgetPrivate::OpenGLWidgetPrivate()
{
	m_shader = QSharedPointer<QOpenGLShaderProgram>(new QOpenGLShaderProgram);
	m_vertexObj = QSharedPointer<VertexObject>(new VertexObject);
	m_textureObj = QSharedPointer<TextureObject>(new TextureObject);
}

OpenGLWidgetPrivate::~OpenGLWidgetPrivate()
{
}
