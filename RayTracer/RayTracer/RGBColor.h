#pragma once
class RGBColor
{
public:
	float r, g, b;
	RGBColor(void);
	RGBColor(const RGBColor& c);
	RGBColor(float c);
	RGBColor(float _r, float _g, float _b);

	~RGBColor();
};

