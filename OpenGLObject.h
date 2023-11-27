#pragma once
#include <QObject>
#include <QOpenGLFunctions_3_3_Core>

class OpenGLObject : protected QOpenGLFunctions_3_3_Core
{
public:
	OpenGLObject();
	~OpenGLObject();

	void updateBufferData(float vertex[], int vertexCount, float index[], int indexCount);
	uint getVAO() { return mVAO; }
	uint getEBO() { return mEBO; }

private:
	uint mVAO;
	uint mVBO;
	uint mEBO;
};

