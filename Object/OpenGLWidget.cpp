#include <QDateTime>
#include <QKeyEvent>
#include "OpenGLWidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
	setFocusPolicy(Qt::StrongFocus);
}

OpenGLWidget::~OpenGLWidget()
{
	for (const auto& m : m_meshes)
		delete m;
	m_meshes.clear();
}

void OpenGLWidget::lineDrawMode(bool open)
{
	m_lineMode = open;
	update();
}

void OpenGLWidget::initializeGL()
{
	// 初始化Opengl函数
	initializeOpenGLFunctions();

	Mesh* mesh = new Mesh();
	mesh->init();
	mesh->compileShader(QString(":/res/Mesh.vsh"), QString(":/res/Mesh.fsh"));
	m_meshes.append(mesh);

	// 顶点、片段着色器
#if 0
	d = QSharedPointer<OpenGLWidgetPrivate>(new OpenGLWidgetPrivate);
	qDebug() << d->m_shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/vertex.vsh");
	qDebug() << d->m_shader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/fragment.fsh");
	qDebug() << d->m_shader->link();

	qDebug() << d->m_lightShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/light.vsh");
	qDebug() << d->m_lightShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/light.fsh");
	qDebug() << d->m_lightShader->link();

#endif
	// 启用Z缓冲
	glEnable(GL_DEPTH_TEST);
}

void OpenGLWidget::resizeGL(int w, int h)
{
}

void OpenGLWidget::paintGL()
{
	// 设置窗口颜色
	glClearColor(0.2, 0.3, 0.1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 线框模式绘制
	GLenum type = m_lineMode ? GL_LINE : GL_FILL;
	glPolygonMode(GL_FRONT_AND_BACK, type);

	for (const auto& m : m_meshes)
	{
		m->draw();
	}

#if 0
	d->m_shader->bind();
	QVector3D lightPos = QVector3D(1.2, 1, 2);
	d->m_shader->setUniformValue("objectColor", 1, 0.5, 0.31);
	d->m_shader->setUniformValue("lightColor", 1, 1, 1);
	d->m_shader->setUniformValue("lightPos", lightPos);
	d->m_shader->setUniformValue("viewPos", d->m_cameraPos);

	QMatrix4x4 model, view, projection;
	model.rotate(d->m_quaternion);
	d->m_shader->setUniformValue("model", model);

	// lookAt矩阵 m_cameraFront表示摄像机一直指向正前方
	view.lookAt(d->m_cameraPos, d->m_cameraPos + d->m_cameraFront, d->m_cameraUp);
	d->m_shader->setUniformValue("view", view);

	projection.perspective(d->m_fov, width() / height(), 0.1, 100);
	d->m_shader->setUniformValue("projection", projection);
	d->m_vertexObj->drawObject();

	// 灯光
	d->m_lightShader->bind();
	d->m_lightShader->setUniformValue("projection", projection);
	d->m_lightShader->setUniformValue("view", view);
	model = QMatrix4x4();
	model.translate(lightPos);
	model.scale(0.2);
	d->m_lightShader->setUniformValue("model", model);
	d->m_lightObj->drawObject();
#endif
}

QPointF OpenGLWidget::pixelPosToViewPos(const QPoint& pos)
{
	double x = 2.0 * (float)pos.x() / width() - 1.0;	//   2x / w - 1
	double y = 1.0 - 2.0 * (float)pos.y() / height();	// -(2y / h - 1)
	return QPointF(x, y);
}

void OpenGLWidget::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Down)
		d->m_cameraPos -= d->m_cameraFront;
	else if (event->key() == Qt::Key_Up)
		d->m_cameraPos += d->m_cameraFront;
	else if (event->key() == Qt::Key_Left)
		d->m_cameraPos -= QVector3D::crossProduct(d->m_cameraFront, d->m_cameraUp).normalized();
	else if (event->key() == Qt::Key_Right)
		d->m_cameraPos += QVector3D::crossProduct(d->m_cameraFront, d->m_cameraUp).normalized();
	update();
	return QWidget::keyPressEvent(event);
}

void OpenGLWidget::mousePressEvent(QMouseEvent* event)
{
#if 0
	if (event->button() != Qt::LeftButton)
		return QWidget::mousePressEvent(event);
	d->m_lastPos = event->pos();
#endif
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{
#if 0
	// 物体旋转
	QPointF lastPos = pixelPosToViewPos(d->m_lastPos);
	QVector3D lastPos3D = QVector3D(lastPos.x(), lastPos.y(), 0);
	float sqrZ = 1 - QVector3D::dotProduct(lastPos3D, lastPos3D);
	sqrZ > 0 ? lastPos3D.setZ(sqrt(sqrZ)) : lastPos3D.normalize();

	QPointF p = pixelPosToViewPos(event->pos());
	QVector3D currentPos3D = QVector3D(p.x(), p.y(), 0);
	sqrZ = 1 - QVector3D::dotProduct(currentPos3D, currentPos3D);
	sqrZ > 0 ? currentPos3D.setZ(sqrt(sqrZ)) : currentPos3D.normalize();

	QVector3D axis = QVector3D::crossProduct(lastPos3D, currentPos3D);
	float angle = asin(axis.length()) * (180 / 3.14159) * 1.2; // 弧度转角度 * 转动速度
	axis.normalize();
	d->m_quaternion = QQuaternion::fromAxisAndAngle(axis, angle) * d->m_quaternion;

	d->m_lastPos = event->pos();
	update();
#endif
}

void OpenGLWidget::wheelEvent(QWheelEvent* event)
{
#if 0
	if (d->m_fov >= 1.0 || d->m_fov <= 60.0)
		d->m_fov -= event->delta() * 0.1;
	if (d->m_fov < 1)
		d->m_fov = 1;
	if (d->m_fov > 60)
		d->m_fov = 60;
	update();
#endif
}
