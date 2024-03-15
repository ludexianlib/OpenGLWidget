#include <QImage>
#include <QDebug>
#include "TextureObject.h"

TextureObject::TextureObject()
{
	// ��ʼ��Opengl����
	initializeOpenGLFunctions();

    m_texture = new QOpenGLTexture(QOpenGLTexture::Target2D);
    m_smileTexture = new QOpenGLTexture(QOpenGLTexture::Target2D);

    loadTexture(m_texture, ":/res/images/woodbox.jpg");
    loadTexture(m_smileTexture, ":/res/images/smile.png");
}

TextureObject::~TextureObject()
{
    delete m_texture;
    delete m_smileTexture;
}

bool TextureObject::loadTexture(QOpenGLTexture* tex, const QString& file)
{
    // ��������
    tex->create();
    tex->setData(QImage(file).mirrored());

    // ���������Ʒ�ʽ s t r�ᣨ��Ӧx y z�ᣩ
    tex->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);
    tex->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);

    // ����������˷�ʽ �Ŵ����С
    tex->generateMipMaps();
    tex->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Linear);
    return true;
}
