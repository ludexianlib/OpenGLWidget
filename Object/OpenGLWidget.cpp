#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
}

void OpenGLWidget::initializeGL()
{
	// 初始化Opengl函数
	initializeOpenGLFunctions();

	d = QSharedPointer<OpenGLWidgetPrivate>(new OpenGLWidgetPrivate);
	d->m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/fragment.vsh");
	d->m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/fragment.fsh");
	d->m_shader->link();
}

void OpenGLWidget::resizeGL(int w, int h)
{
}

void OpenGLWidget::paintGL()
{
	// 设置窗口颜色
	glClearColor(0.1f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	d->m_shader->bind();
	glBindVertexArray(d->m_vertexObj->m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
