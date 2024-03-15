#include <QDateTime>
#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
}

void OpenGLWidget::lineDrawMode(bool open)
{
	d->m_lineMode = open;
	update();
}

void OpenGLWidget::initializeGL()
{
	// 初始化Opengl函数
	initializeOpenGLFunctions();

	// 顶点、片段着色器
	d = QSharedPointer<OpenGLWidgetPrivate>(new OpenGLWidgetPrivate);
	qDebug() << d->m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/vertex.vsh");
	qDebug() << d->m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/fragment.fsh");
	qDebug() << d->m_shader->link();
}

void OpenGLWidget::resizeGL(int w, int h)
{
}

void OpenGLWidget::paintGL()
{
	// 设置窗口颜色
	glClearColor(0.1f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 线框模式绘制
	d->m_lineMode ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	d->m_shader->bind();

	d->m_shader->setUniformValue("outTexture", 0);
	d->m_textureObj->m_texture->bind(0);
	d->m_shader->setUniformValue("smileTexture", 1);
	d->m_textureObj->m_smileTexture->bind(1);

	glBindVertexArray(d->m_vertexObj->m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
