#include "stdafx.h"
#include "Normal.h"
#include <math.h>

Normal::Normal()
{
}
Normal::Normal(void)
	: x(0.0), y(0.0), z(0.0)
{}


// ---------------------------------------------------------- constructor

Normal::Normal(double a)
	: x(a), y(a), z(a)
{}


// ---------------------------------------------------------- constructor

Normal::Normal(double _x, double _y, double _z)
	: x(_x), y(_y), z(_z)
{}


// ---------------------------------------------------------- copy constructor

Normal::Normal(const Normal& n)
	: x(n.x), y(n.y), z(n.z)
{}


// ---------------------------------------------------------- constructor
// construct a normal from a vector

Normal::Normal(const Vector3D& v)
	: x(v.x), y(v.y), z(v.z)
{}


// ---------------------------------------------------------- destructor

Normal::~Normal(void)
{}


// ----------------------------------------------------------- operator=
// assignment operator

Normal&
Normal::operator= (const Normal& rhs) {
	if (this == &rhs)
		return (*this);

	x = rhs.x; y = rhs.y; z = rhs.z;

	return (*this);
}


// ------------------------------------------------------------ operator=
// assignment of a vector to a normal

Normal&
Normal::operator= (const Vector3D& rhs) {
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}


// ------------------------------------------------------------ operator=
// assignment of a point to a normal

Normal&
Normal::operator= (const Point3D& rhs) {
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}


// ------------------------------------------------------------ normalize

void
Normal::normalize(void) {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
}



Normal::~Normal()
{
}
