#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

OpenGLWidget::~OpenGLWidget()
{
	delete openglObject;
	delete mShader;
}

void OpenGLWidget::initializeGL()
{
	// 初始化Opengl函数
	initializeOpenGLFunctions();

	mShader = new QOpenGLShaderProgram();
	mShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/fragment.vsh");
	mShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/fragment.fsh");
	mShader->link();

	openglObject = new OpenGLObject;
	float vertex[] = {
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};
	float index[] = {
		0, 1, 3,
		1, 2, 3
	};
	int vertexCount = sizeof(vertex) / sizeof(float);
	int indexCount = sizeof(index) / sizeof(float);
	openglObject->updateBufferData(vertex, vertexCount, index, indexCount);
}

void OpenGLWidget::resizeGL(int w, int h)
{
}

void OpenGLWidget::paintGL()
{
	// 设置窗口颜色
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mShader->bind();

	glBindVertexArray(openglObject->getVAO());
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
