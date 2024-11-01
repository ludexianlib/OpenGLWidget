#pragma once
#include <QWidget>
#include <QOpenGLWidget>

#include "OpenGLWidgetPrivate.h"
#include "VertexObject/Mesh.h"

class OpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget();

	void lineDrawMode(bool open);
	QPointF pixelPosToViewPos(const QPoint& pos);

protected:
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;

	void keyPressEvent(QKeyEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;

private:
	QSharedPointer<OpenGLWidgetPrivate> d;

	QList<Mesh*> m_meshes;
	bool m_lineMode = false;
};
