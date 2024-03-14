#pragma once
#include <QTimer>
#include <QSharedPointer>
#include <QOpenGLShaderProgram>

#include "VertexObject.h"

class OpenGLWidgetPrivate
{
public:
	OpenGLWidgetPrivate();
	~OpenGLWidgetPrivate();

public:
	QSharedPointer<QOpenGLShaderProgram> m_shader;
	QSharedPointer<VertexObject> m_vertexObj;

	bool m_lineMode = false;		// 是否以线框模式绘制

	QVector4D m_colorVec;
	QTimer* m_timer = nullptr;
};