#pragma once
#include <QWidget>
#include "Object/OpenGLWidget.h"

class Widget : public QWidget
{
public: 
	Widget(QWidget *parent = nullptr);
private:
	OpenGLWidget *openglWidget;
};

