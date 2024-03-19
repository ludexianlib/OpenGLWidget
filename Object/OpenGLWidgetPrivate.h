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

	// 摄像机参数
	QVector3D m_cameraPos{0, 0, 3};
	QVector3D m_cameraFront{0, 0, -1};
	QVector3D m_cameraUp{0, 1, 0};

	// 鼠标旋转事件
	QPoint m_lastPos;
	QQuaternion m_quaternion;
	
	// 鼠标缩放视角
	double m_fov = 45.0;

	QTimer* m_timer = nullptr;
};