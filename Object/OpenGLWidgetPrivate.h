#pragma once
#include <QTimer>
#include <QVector3D>
#include <QSharedPointer>
#include <QOpenGLShaderProgram>

#include "VertexObject.h"
#include "TextureObject.h"

class OpenGLWidgetPrivate
{
public:
	OpenGLWidgetPrivate();
	~OpenGLWidgetPrivate();

public:
	QSharedPointer<QOpenGLShaderProgram> m_shader;
	QSharedPointer<VertexObject> m_vertexObj;
	QSharedPointer<TextureObject> m_textureObj;

	bool m_lineMode = false;		// 是否以线框模式绘制

	int m_rotateAngle = 0;
	QVector4D m_colorVec;
	QVector3D m_cameraPos;
	QTimer* m_timer = nullptr;
};