#ifndef _VECTOR3_H
#define _VECTOR3_H
#include<cmath>
#include<GL/glut.h>

class Vector3
{
public:

	// A default constructor
	Vector3();

	// This is our constructor that allows us to initialize our data upon creating an instance
	Vector3(double X, double Y, double Z);

	double Distance(Vector3);

	// Here we overload the + operator so we can add vectors together 
	Vector3 operator + (Vector3);

	// Here we overload the - operator so we can subtract vectors 
	Vector3 operator - (Vector3);

	// Here we overload the * operator so we can multiply by scalars
	Vector3 operator * (double scalar);

	// Here we overload the / operator so we can divide by a scalar
	Vector3 operator / (double scalar);

	double x, y, z;

};

#endif // !_VECTOR3_H


#pragma once
