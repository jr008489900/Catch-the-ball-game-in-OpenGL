#ifndef _FRUIT_H
#define _FRUIT_H

#include"Vector3.h"
#include<vector>
#include<GL/glut.h>
using namespace std;

class Fruit
{
public:
	Fruit();
	Fruit(Vector3);
	Vector3 Position() { return f_Position; }
	void SetPosition(Vector3);
	void SetVelocity(Vector3);
	double GetRadius() {return radius; }
	void ResetRandomFruit(int height);
	void Update();
	void Draw();
	bool isalive;
	int type;

private:

	double radius;

	//the fruit's position
	Vector3 f_Position;

	//the fruit's velocity
	Vector3 f_Velocity;
};


#endif
#pragma once
