#include "stdafx.h"
#include "Light.h"
#include "Point3D.h"
#include "RGBColor.h"

Light::Light()
{
}
Light::Light(Point3D p, RGBColor c)
	:location(p), color(c){}
	

Light::~Light()
{
}
