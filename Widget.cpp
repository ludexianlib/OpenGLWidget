#include <QMenuBar>
#include <QHBoxLayout>
#include "Widget.h"

#ifndef STR
#define STR(str) QObject::tr(u8 ## str)
#endif // !STR

Widget::Widget(QWidget * parent) : QMainWindow(parent)
{
	QHBoxLayout *layout = new QHBoxLayout;
	QWidget *widget = new QWidget(this);

	// 创建OpenglWidget
	m_openglWidget = new OpenGLWidget(this);

	// 菜单栏
	QMenu *changedMode = menuBar()->addMenu(STR("切换"));
	m_lineMode = changedMode->addAction(STR("线框模式"));
	m_lineMode->setCheckable(true);
	connect(m_lineMode, &QAction::triggered, [&]() {
		m_openglWidget->lineDrawMode(m_lineMode->isChecked());
	});

	layout->addWidget(m_openglWidget);
	layout->setMargin(0);
	widget->setLayout(layout);
	
	setCentralWidget(widget);
	setMinimumSize(800, 600);
}
