#pragma once
#include "Vector3D.h"
#include "Point3D.h"
class Normal
{
public:
	double	x, y, z;

	Normal();
	Normal(double a);									// constructor
	Normal(double _x, double _y, double _z);			// constructor
	Normal(const Normal& n); 							// copy constructor
	Normal(const Vector3D& v);							// constructs a normal from a vector

	~Normal();

	Normal& 											// assignment operator
		operator= (const Normal& rhs);

	Normal& 											// assignment of a vector to a normal
		operator= (const Vector3D& rhs);

	Normal& 											// assignment of a point to a normal
		operator= (const Point3D& rhs);

	Normal 												// unary minus
		operator- (void) const;

	Normal 												// addition
		operator+ (const Normal& n) const;

	Normal& 											// compound addition
		operator+= (const Normal& n);

	double
		operator* (const Vector3D& v) const;				// dot product with a vector on the right

	Normal 												// multiplication by a double on the right
		operator* (const double a) const;

	void 												// convert normal to a unit normal
		normalize(void);

};

