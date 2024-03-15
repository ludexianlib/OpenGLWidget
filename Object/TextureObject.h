#pragma once
#include <QOpenGLTexture>
#include <QOpenGLFunctions_3_3_Core>

class TextureObject : public QOpenGLFunctions_3_3_Core
{
public:
	TextureObject();
	~TextureObject();

	bool loadTexture(QOpenGLTexture* tex, const QString& file);

public:
	QOpenGLTexture *m_texture;
	QOpenGLTexture *m_smileTexture;
};