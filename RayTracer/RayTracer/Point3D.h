#pragma once
#include "Vector3D.h"

class Point3D
{
public:
	double x, y, z;

	Point3D();
	Point3D(const double a);
	Point3D(const double a, const double b, const double c);
	
	inline Vector3D
		Point3D::operator- (const Point3D& p) const {
		return (Vector3D((float)(x - p.x), (float)(y - p.y), (float)(z - p.z)));
	}
	inline Point3D
		Point3D::operator- (const Vector3D& p) const {
		return (Point3D((float)(x - p.x), (float)(y - p.y), (float)(z - p.z)));
	}

	inline Vector3D
		Point3D::operator- (const double& p) const {
		return (Vector3D(x-p,y-z,z-p));
	}
	inline Point3D
		Point3D::operator+ (const Vector3D& v) const {
		return (Point3D(x + v.x, y + v.y, z + v.z));
	}

	inline Point3D
		Point3D::operator+ (const Point3D& v) const {
		return (Point3D(x + v.x, y + v.y, z + v.z));
	}
	inline Point3D
		Point3D::operator+ (const float& v) const {
		return (Point3D(x + v, y + v, z + v));
	}

	inline Point3D
		Point3D::operator* (const double v) const {
		return (Point3D(x*v,y*v,z*v));
	}
	inline double
		Point3D::operator* (const Vector3D& vectorIn) const {
		return (x * vectorIn.x + y * vectorIn.y + z * vectorIn.z);
	}
	inline Point3D
		Point3D::operator^ (const Point3D& vectorIn) const {
		return (Point3D(y * vectorIn.z - z * vectorIn.y, z * vectorIn.x - x * vectorIn.z, x * vectorIn.y - y * vectorIn.x));
	}


	Point3D& norm(){ return *this = *this * (1 / sqrt(x*x + y*y + z*z)); }


	~Point3D();

};

