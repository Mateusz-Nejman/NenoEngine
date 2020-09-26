#pragma once
class Color
{
public:
	double r, g, b;

	Color(int r, int g, int b)
	{
		this->r = (1.0 / 255.0) * (double)r;
		this->g = (1.0 / 255.0) * (double)g;
		this->b = (1.0 / 255.0) * (double)b;
	}

	Color(double r, double g, double b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
};

