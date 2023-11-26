#pragma once

#include <QtWidgets/QWidget>

class OpenGLWidget : public QWidget
{
    Q_OBJECT

public:
    OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget();

};
