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
	// ��ʼ��Opengl����
	initializeOpenGLFunctions();

	// ���㡢Ƭ����ɫ��
	d = QSharedPointer<OpenGLWidgetPrivate>(new OpenGLWidgetPrivate);
	bool succeed = false;
	succeed = d->m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/vertex.vsh");
	succeed = d->m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/fragment.fsh");
	succeed = d->m_shader->link();
}

void OpenGLWidget::resizeGL(int w, int h)
{
}

void OpenGLWidget::paintGL()
{
	// ���ô�����ɫ
	glClearColor(0.1f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// �߿�ģʽ����
	d->m_lineMode ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	d->m_shader->bind();
	glBindVertexArray(d->m_vertexObj->m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
