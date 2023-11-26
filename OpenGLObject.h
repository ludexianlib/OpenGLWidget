#pragma once
#include <QObject>
#include <QOpenGLFunctions_3_3_Core>

class OpenGLObject : protected QOpenGLFunctions_3_3_Core
{
public:
	OpenGLObject();
	~OpenGLObject();

	void updateBufferData(float vertex[], int length);
	uint getVAO() { return mVAO; }

private:
	uint mVAO;
	uint mVBO;
};

