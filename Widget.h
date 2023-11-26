#pragma once
#include <QWidget>
#include "OpenGLWidget.h"

class Widget : public QWidget
{
public: 
	Widget(QWidget *parent = nullptr);
private:
	OpenGLWidget *openglWidget;
};

