#pragma once
#include <QObject>
#include <QOpenGLFunctions_3_3_Core>

class LightObject : public QOpenGLFunctions_3_3_Core
{
public:
	LightObject();
	~LightObject();

	void drawObject();

public:
	uint m_VAO = 0;
	uint m_VBO = 0;
};