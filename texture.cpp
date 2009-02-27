#include "texture.h"

#include <QImage>
#include <qgl.h>

Texture::Texture() : texture(0)
{
}

Texture::Texture(const uint rgb, const QString &path, float x, float y, bool readfile) : sizex(x), sizey(y)
{
	QImage t;

	if (! readfile) {
		QImage v;

		if (path.isEmpty() || !v.load(path) ) {
			v = QImage(16, 16, QImage::Format_ARGB32);
			v.fill( rgb );
		}

		t = QGLWidget::convertToGLFormat(v);
	} else {

		QByteArray array = QByteArray::fromBase64(path.toAscii());

		QImage v;
		v.loadFromData(array);

		t = QGLWidget::convertToGLFormat(v);
	}

	glGenTextures(1, &texture);
	glBindTexture( GL_TEXTURE_2D, texture);

	glTexImage2D( GL_TEXTURE_2D, 0, 3, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits() );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
}

void Texture::destroy()
{
	glDeleteTextures(1, &texture);
}
