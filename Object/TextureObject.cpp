#include <QImage>
#include <QDebug>
#include "TextureObject.h"

TextureObject::TextureObject()
{
	// 初始化Opengl函数
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
    // 加载纹理
    tex->create();
    tex->setData(QImage(file).mirrored());

    // 设置纹理环绕方式 s t r轴（对应x y z轴）
    tex->setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);
    tex->setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);

    // 设置纹理过滤方式 放大和缩小
    tex->generateMipMaps();
    tex->setMinMagFilters(QOpenGLTexture::Nearest, QOpenGLTexture::Linear);
    return true;
}
