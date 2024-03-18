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
	// ��ʼ��Opengl����
	initializeOpenGLFunctions();

	// ���㡢Ƭ����ɫ��
	d = QSharedPointer<OpenGLWidgetPrivate>(new OpenGLWidgetPrivate);
	qDebug() << d->m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/vertex.vsh");
	qDebug() << d->m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/fragment.fsh");
	qDebug() << d->m_shader->link();

	// ����Z����
	glEnable(GL_DEPTH_TEST);

	d->m_timer = new QTimer(this);
	connect(d->m_timer, &QTimer::timeout, [&]() {
		static int i = 0;
		if (i++ > 360)
			i = 0;
		d->m_rotateAngle = i;
		double radius = 10;
		double sinC = sin(3.14159 / 180.0 * i) * 10;
		double cosC = cos(3.14159 / 180.0 * i) * 10;
		d->m_cameraPos = QVector3D(sinC, 0, cosC);
		update();
	});
	d->m_timer->start(20);
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

	d->m_shader->setUniformValue("outTexture", 0);
	d->m_textureObj->m_texture->bind(0);
	d->m_shader->setUniformValue("smileTexture", 1);
	d->m_textureObj->m_smileTexture->bind(1);

	QMatrix4x4 model, view, projection;
	model.rotate(d->m_rotateAngle, 1, 0, 0);
	d->m_shader->setUniformValue("model", model);

	// lookAt���� 1.���λ�� 2.�۲�λ�� 3.������
	view.lookAt(d->m_cameraPos, QVector3D(0, 0, 0), QVector3D(0, 1, 0));
	d->m_shader->setUniformValue("view", view);

	projection.perspective(45, width() / height(), 0.1, 100);
	d->m_shader->setUniformValue("projection", projection);

	d->m_vertexObj->drawObject();

	model = QMatrix4x4();
	model.translate(0.7, 0.5, 0);
	d->m_shader->setUniformValue("model", model);
	d->m_vertexObj->drawObject();
}
