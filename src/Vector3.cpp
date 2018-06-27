#include"Vector3.h"

Vector3::Vector3() {}

Vector3::Vector3(double X,double Y,double Z) 
{
	x = X, y = Y, z = Z;
}

Vector3 Vector3::operator + (Vector3 vec3) 
{
	return Vector3(this->x + vec3.x, this->y + vec3.y, this->z + vec3.z);
}

Vector3 Vector3::operator - (Vector3 vec3)
{
	return Vector3(this->x - vec3.x, this->y - vec3.y, this->z - vec3.z);
}

Vector3 Vector3::operator * (double scalar)
{
	return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3 Vector3::operator / (double scalar)
{
	return Vector3(this->x / scalar, this->y / scalar, this->z / scalar);
}

double Vector3::Distance(Vector3 vec3)
{
	return std::sqrt((this->x - vec3.x)*(this->x - vec3.x) + (this->y - vec3.y)* (this->y - vec3.y) + (this->z - vec3.z)* (this->z - vec3.z));
}