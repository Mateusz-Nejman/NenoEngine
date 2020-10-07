#include "Sprite.h"

namespace neno
{
	Sprite::~Sprite()
	{
		delete color;
		color = nullptr;
		texture = nullptr;
	}

	Sprite::Sprite(Texture* texture)
	{
		Initialize(texture);
	}

	Sprite::Sprite(Texture* texture, int x, int y)
	{
		Initialize(texture, x, y);
	}

	Sprite::Sprite(Texture* texture, int x, int y, int width, int height)
	{
		Initialize(texture, x, y, width, height);
	}

	Sprite::Sprite(Texture* texture, int x, int y, int width, int height, int originX, int originY)
	{
		Initialize(texture, x, y, width, height, originX, originY);
	}

	Sprite::Sprite(Texture* texture, int x, int y, int width, int height, int originX, int originY, double scaleX, double scaleY)
	{
		Initialize(texture, x, y, width, height, originX, originY, scaleX, scaleY);
	}

	Sprite::Sprite(Texture* texture, int x, int y, int width, int height, int originX, int originY, double scaleX, double scaleY, double angle)
	{
		Initialize(texture, x, y, width, height, originX, originY, scaleX, scaleY, angle);
	}

	Sprite::Sprite(Texture* texture, int x, int y, int width, int height, int originX, int originY, double scaleX, double scaleY, double angle, Color* color)
	{
		Initialize(texture, x, y, width, height, originX, originY, scaleX, scaleY, angle, color);
	}

	void Sprite::Initialize(Texture* texture, int x, int y, int width, int height, int originX, int originY, double scaleX, double scaleY, double angle, Color* color)
	{
		this->texture = texture;
		this->x = 0;
		this->y = 0;

		if (width == -1)
			this->width = texture->width;
		else
			this->width = width;

		if (height == -1)
			this->height = texture->height;
		else
			this->height = height;

		this->originX = originX;
		this->originY = originY;
		this->scaleX = scaleX;
		this->scaleY = scaleY;
		this->angle = angle;
		if (color == nullptr)
			this->color = Color::White.Clone();
		else
			this->color = color;
	}

	void Sprite::Draw()
	{
		int newX = (int)((double)x * scaleX);
		int newY = (int)((double)y * scaleY);
		int newOriginX = (int)((double)originX * scaleX);
		int newOriginY = (int)((double)originY * scaleY);
		int newWidth = (int)((double)width * scaleX);
		int newHeight = (int)((double)height * scaleY);
		glPushMatrix();
		glTranslated(newX, newY, 0);
		glRotated(-angle, 0, 0, 1.0);
		texture->Draw(-newOriginX, -newOriginY, newWidth, newHeight, *color);
		glPopMatrix();
	}
}