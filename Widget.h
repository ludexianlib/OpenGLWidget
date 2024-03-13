#pragma once
#include <QMainWindow>
#include "Object/OpenGLWidget.h"

class Widget : public QMainWindow
{
public: 
	Widget(QWidget *parent = nullptr);

private:
	OpenGLWidget *m_openglWidget;
	QAction *m_lineMode;
};

