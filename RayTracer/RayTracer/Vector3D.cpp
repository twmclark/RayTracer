#include "stdafx.h"
#include "Vector3D.h"
#include <math.h>
Vector3D::Vector3D(float x_,float y_, float z_)
	: x(x_), y(y_), z(z_)
{
}
double Vector3D:: length(void){
	return (sqrt(x * x + y * y + z * z));
}

void Vector3D::normalize(void){
	double length = this->length();
	x /= length; 	y /= length;	z /= length;
}

Vector3D::Vector3D()
{
	
}


Vector3D::~Vector3D()
{
}
