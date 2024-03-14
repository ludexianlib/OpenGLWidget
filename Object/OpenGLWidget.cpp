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
	d->m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/fragment.vsh");
	d->m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/fragment.fsh");
	d->m_shader->link();

	d->m_timer = new QTimer(this);
	connect(d->m_timer, &QTimer::timeout, [this]() {
		static int i = 0;
		if (i++ > 360)
			i = 0;
		d->m_colorVec = QVector4D(0, sin(3.14159 / 180.0 * i), 0, 1);
		update();
	});
	d->m_timer->start(20);
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
	d->m_shader->setUniformValue("outColor", d->m_colorVec);

	glBindVertexArray(d->m_vertexObj->m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
