#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
	delete openglObject;
}

void OpenGLWidget::initializeGL()
{
	// ��ʼ��Opengl����
	initializeOpenGLFunctions();

	openglObject = new OpenGLObject;
	float vertex[] = {
	-0.5, -0.5, 0.0,
	 0.5, -0.5, 0.0,
	 0.0,  0.5, 0.0
	};

	openglObject->updateBufferData(vertex, sizeof(vertex) / sizeof(float));
}

void OpenGLWidget::resizeGL(int w, int h)
{
}

void OpenGLWidget::paintGL()
{
	// ���ô�����ɫ
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBindVertexArray(openglObject->getVAO());
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
