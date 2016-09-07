#pragma once
#include <math.h>
class Vector3D
{
private:
	

public:
	float x, y, z;
	Vector3D(float x_, float y_, float z_);
	
	double length(void);

	void normalize(void);

	Vector3D operator+(const Vector3D& vectorIn){
		Vector3D vector;
		vector.x = this->x + vectorIn.x;
		vector.y = this->y + vectorIn.y;
		vector.z = this->z + vectorIn.z;
		return vector;
	}
	
	Vector3D operator-(const Vector3D& vectorIn){
		Vector3D vector;
		vector.x = this->x - vectorIn.x;
		vector.y = this->y - vectorIn.y;
		vector.z = this->z - vectorIn.z;
		return vector;
	}
	
	Vector3D Vector3D::operator-()const{
		return Vector3D(-x, -y, -z);
	}

	Vector3D operator/(const float a)const{
		return (Vector3D(x/a, y/a, z/a));
	}
	//dot product 	Cos(theta) = DotProduct(v1,v2) / (length(v1) * length(v2))
	inline double
		Vector3D::operator* (const Vector3D& vectorIn) const {
		return (x * vectorIn.x + y * vectorIn.y + z * vectorIn.z);
	}
	
	//dot product
	friend Vector3D operator * (const Vector3D& v, float f) { return Vector3D(v.x * f, v.y * f, v.z * f); }

	//cross product
	inline Vector3D
		Vector3D::operator^ (const Vector3D& vectorIn) const {
		return (Vector3D(y * vectorIn.z - z * vectorIn.y, z * vectorIn.x - x * vectorIn.z, x * vectorIn.y - y * vectorIn.x));
	}
	Vector3D& norm(){ return *this = *this * (1 / sqrt(x*x + y*y + z*z)); }
	
	Vector3D negative(){
		return Vector3D(-x, -y, -z);
	}
	


	float getX(){
		return x;
	}
	float getY(){
		return y;
	}
	float getZ(){
		return z;
	}

	void setX(float x_){
		x = x_;
	}
	void setY(float y_){
		y = y_;
	}
	void setZ(float z_){
		z = z_;
	}
	Vector3D();
	~Vector3D();
};

