#include <QHBoxLayout>
#include "Widget.h"

Widget::Widget(QWidget * parent)
{
	QHBoxLayout *layout = new QHBoxLayout;

	// ´´½¨OpenglWidget
	openglWidget = new OpenGLWidget(this);
	layout->addWidget(openglWidget);

	layout->setMargin(0);
	setLayout(layout);
	setMinimumSize(800, 600);
}
