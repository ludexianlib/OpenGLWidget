#pragma once

#include <QtWidgets/QWidget>
#include "ui_OpenGLWidget.h"

class OpenGLWidget : public QWidget
{
    Q_OBJECT

public:
    OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget();

private:
    Ui::OpenGLWidgetClass ui;
};
