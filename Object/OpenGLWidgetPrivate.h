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

	bool m_lineMode = false;		// �Ƿ����߿�ģʽ����

	int m_rotateAngle = 0;
	QVector4D m_colorVec;

	QVector3D m_cameraPos{0, 0, 3};
	QVector3D m_cameraFront{0, 0, -1};
	QVector3D m_cameraUp{0, 1, 0};

	QTimer* m_timer = nullptr;
};