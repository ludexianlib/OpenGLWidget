#pragma once
#include <QWidget>
#include <QOpenGLWidget>

#include "OpenGLWidgetPrivate.h"

class OpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget();

protected:
	void initializeGL() override;
	void resizeGL(int w, int h) override;
	void paintGL() override;

private:
	QSharedPointer<OpenGLWidgetPrivate> d;
};
