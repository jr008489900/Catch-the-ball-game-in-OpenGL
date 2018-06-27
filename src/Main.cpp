#include<cmath>
#include<Windows.h>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<GL\glut.h>
#include"Camera.h"
#include"Fruit.h"
#include"Texture.h"
#include"Text.h"

using namespace std;
CCamera myCamera;

Text pScore;
int score = 0;
int life = 20;

const int BallHeight = 50;

//the interval between the ball and ball.
const int Interval = 20;
vector<Fruit> myfruit;

/*******************************/
#define MAX_VERTICES 2000 // Max number of vertices (for each object)
#define MAX_POLYGONS 2000 // Max number of polygons (for each object)


/**********************************************************
*
* TYPES DECLARATION
*
*********************************************************/

// Our vertex type
typedef struct {
	float x, y, z;
}vertex_type;

// The polygon (triangle), 3 numbers that aim 3 vertices
typedef struct {
	int a, b, c;
}polygon_type;

// The mapcoord type, 2 texture coordinates for each vertex
typedef struct {
	float u, v;
}mapcoord_type;

// The object type
typedef struct {
	vertex_type vertex[MAX_VERTICES];
	polygon_type polygon[MAX_POLYGONS];
	mapcoord_type mapcoord[MAX_VERTICES];
	int id_texture;
} obj_type, *obj_type_ptr;



/**********************************************************
*
* VARIABLES DECLARATION
*
*********************************************************/

// Flag for rendering as lines or filled polygons
int filling = 1; //0=OFF 1=ON

				 // And, finally our first object!
obj_type cube =
{
	{
		-10*5, 0, 10*5,   // vertex v0
		10*5,  0, 10*5,   // vertex v1
		10*5,  0, -10*5,  // vertex v2
		-10*5, 0, -10*5,  // vertex v3
		-10*5, 50,  10*5,   // vertex v4
		10*5,  50,  10*5,   // vertex v5
		10*5,  50,  -10*5,  // vertex v6 
		-10*5, 50,  -10*5   // vertex v7
	},
	{
		0, 1, 4,  // polygon v0,v1,v4
		1, 5, 4,  // polygon v1,v5,v4
		1, 2, 5,  // polygon v1,v2,v5
		2, 6, 5,  // polygon v2,v6,v5
		2, 3, 6,  // polygon v2,v3,v6
		3, 7, 6,  // polygon v3,v7,v6
		3, 0, 7,  // polygon v3,v0,v7
		0, 4, 7,  // polygon v0,v4,v7
		//4, 5, 7,  // polygon v4,v5,v7
		//5, 6, 7,  // polygon v5,v6,v7
		3, 2, 0,  // polygon v3,v2,v0
		2, 1, 0   // polygon v2,v1,v0
	},
	{
		0.0, 0.0,  // mapping coordinates for vertex v0 ok
		1.0, 0.0,  // mapping coordinates for vertex v1 ok
		1.0, 1.0,  // mapping coordinates for vertex v2 
		0.0, 1.0,  // mapping coordinates for vertex v3 ok
		0.0, 1.0,  // mapping coordinates for vertex v4 ok
		1.0, 1.0,  // mapping coordinates for vertex v5 
		1.0, 0.0,  // mapping coordinates for vertex v6 ok
		0.0, 0.0   // mapping coordinates for vertex v7 ok
	},
	0
};
/*********************************/



void init()
{
	glClearColor(0.9, 0.9, 0.9, 1);
	glColor3d(1, 1, 1);
	glShadeModel(GL_SMOOTH); // Type of shading for the polygons
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluPerspective(60.0f, (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 1.0f, 150.0f);
	glMatrixMode(GL_MODELVIEW);


	//glEnable(GL_TEXTURE_2D); // This Enable the Texture mapping
	char str[] = "Stone.bmp";
	cube.id_texture = LoadBitmap(str); // The Function LoadBitmap() return the current texture ID

									   // If the last function returns -1 it means the file was not found so we exit from the program
	if (cube.id_texture == -1)
	{
		MessageBox(NULL, "Image file: texture1.bmp not found", "Zetadeck", MB_OK | MB_ICONERROR);
		exit(0);
	}
	/********************************************************/

	myfruit.push_back(Fruit(Vector3(25, 40, 6)));
	myfruit.push_back(Fruit(Vector3(-25, 35, 6)));
	myfruit.push_back(Fruit(Vector3(5, 45, -19)));
	myfruit.push_back(Fruit(Vector3(10, 40, -10)));
	myfruit.push_back(Fruit(Vector3(0, 50, 20)));
	for (int i = 0; i < myfruit.size(); i++)
	{
		myfruit[i].ResetRandomFruit(BallHeight+15*i);
	}

	myCamera.PositionCamera(0, 2, 6, 0, 3, 0, 0, 1, 0);
}

void CreatWorld()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, cube.id_texture); // We set the active texture 

	glBegin(GL_TRIANGLES); // GlBegin and glEnd delimit the vertices that define a primitive (in our case triangles)

	for (int l_index = 0,j=0; l_index<12; l_index += 2,j++)
	{

		//----------------- FIRST VERTEX -----------------
		// Texture coordinates of the first vertex
		/*glTexCoord2f( cube.mapcoord[ cube.polygon[l_index].a ].u,
		cube.mapcoord[ cube.polygon[l_index].a ].v);*/
		glTexCoord2f(0, 0);
		// Coordinates of the first vertex
		glVertex3f(cube.vertex[cube.polygon[l_index].a].x,
			cube.vertex[cube.polygon[l_index].a].y,
			cube.vertex[cube.polygon[l_index].a].z); //Vertex definition

													 //----------------- SECOND VERTEX -----------------
													 // Texture coordinates of the second vertex
		glTexCoord2f(1, 0);
		// Coordinates of the second vertex
		glVertex3f(cube.vertex[cube.polygon[l_index].b].x,
			cube.vertex[cube.polygon[l_index].b].y,
			cube.vertex[cube.polygon[l_index].b].z);

		//----------------- THIRD VERTEX -----------------
		// Texture coordinates of the third vertex
		glTexCoord2f(0, 1);
		// Coordinates of the Third vertex
		glVertex3f(cube.vertex[cube.polygon[l_index].c].x,
			cube.vertex[cube.polygon[l_index].c].y,
			cube.vertex[cube.polygon[l_index].c].z);
	}
	for (int l_index = 1,j=0; l_index<12; l_index += 2,j++)
	{
		//----------------- FIRST VERTEX -----------------
		// Texture coordinates of the first vertex
		glTexCoord2f(1, 0);
		// Coordinates of the first vertex
		glVertex3f(cube.vertex[cube.polygon[l_index].a].x,
			cube.vertex[cube.polygon[l_index].a].y,
			cube.vertex[cube.polygon[l_index].a].z); //Vertex definition

													 //----------------- SECOND VERTEX -----------------
													 // Texture coordinates of the second vertex
		glTexCoord2f(1, 1);
		// Coordinates of the second vertex
		glVertex3f(cube.vertex[cube.polygon[l_index].b].x,
			cube.vertex[cube.polygon[l_index].b].y,
			cube.vertex[cube.polygon[l_index].b].z);

		//----------------- THIRD VERTEX -----------------
		// Texture coordinates of the third vertex
		glTexCoord2f(0, 1);
		// Coordinates of the Third vertex
		glVertex3f(cube.vertex[cube.polygon[l_index].c].x,
			cube.vertex[cube.polygon[l_index].c].y,
			cube.vertex[cube.polygon[l_index].c].z);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

}

void CreatePyramid(float x, float y, float z, int width, int height)
{
	// Below we create a pyramid (hence CreatePyramid() :).  This entails
	// 4 triangles for the sides and one QUAD for the bottom.  We could have done
	// 2 triangles instead of a QUAD but it's less code and seemed appropriate.
	// We also assign some different colors to each vertex to add better visibility.
	// The pyramid will be centered around (x, y, z).  This code is also used in the
	// lighting and fog tutorial on our site at www.GameTutorials.com.

	// Start rendering the 4 triangles for the sides
	glBegin(GL_TRIANGLES);

	// These vertices create the Back Side
	glColor3ub(255, 0, 0);   glVertex3f(x, y + height, z);					// Top point
	glColor3ub(0, 255, 255); glVertex3f(x - width, y - height, z - width);	// Bottom left point
	glColor3ub(255, 0, 255); glVertex3f(x + width, y - height, z - width);  // Bottom right point

																			// These vertices create the Front Side
	glColor3ub(255, 0, 0);   glVertex3f(x, y + height, z);					// Top point
	glColor3ub(0, 255, 255); glVertex3f(x + width, y - height, z + width);  // Bottom right point
	glColor3ub(255, 0, 255); glVertex3f(x - width, y - height, z + width);	// Bottom left point

																			// These vertices create the Front Left Side
	glColor3ub(255, 0, 0);   glVertex3f(x, y + height, z);					// Top point
	glColor3ub(255, 0, 255); glVertex3f(x - width, y - height, z + width);	// Front bottom point
	glColor3ub(0, 255, 255); glVertex3f(x - width, y - height, z - width);	// Bottom back point

																			// These vertices create the Front Right Side
	glColor3ub(255, 0, 0);   glVertex3f(x, y + height, z);					// Top point
	glColor3ub(255, 0, 255); glVertex3f(x + width, y - height, z - width);	// Bottom back point
	glColor3ub(0, 255, 255); glVertex3f(x + width, y - height, z + width);	// Front bottom point

	glEnd();

	// Now render the bottom of our pyramid

	glBegin(GL_QUADS);

	// These vertices create the bottom of the pyramid
	glColor3ub(0, 0, 255); glVertex3f(x - width, y - height, z + width);	// Front left point
	glColor3ub(0, 0, 255); glVertex3f(x + width, y - height, z + width);    // Front right point
	glColor3ub(0, 0, 255); glVertex3f(x + width, y - height, z - width);    // Back right point
	glColor3ub(0, 0, 255); glVertex3f(x - width, y - height, z - width);    // Back left point
	glEnd();
}


///////////////////////////////// DRAW 3D GRID \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////	This function create a simple grid to get a better view of the animation
/////
///////////////////////////////// DRAW 3D GRID \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void DrawInterFace()
{
	glLoadIdentity();
	char str[1024] = "SCORE";

	/*Print the title of the "Score"*/
	glPushMatrix();
		GLfloat mat_ambient[4] = { 0,0.0,0,1 };
		GLfloat mat_diffuse[4] = { 0,0,0,1 };
		GLfloat mat_specular[4] = { 0.6,0.6,0.6,1 };
		GLfloat mat_shininess = 32.0;
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

		glLineWidth(5);
		glTranslated(-0.7, -0.5, -1);
		glScaled(0.003,0.003, 0.003);
		pScore.PrintStr(str);
	glPopMatrix();
	
	//Print the Value of the Score.
	glPushMatrix();
		GLfloat mat2_ambient[4] = { 0,0.0,0,1 };
		GLfloat mat2_diffuse[4] = { 0,0,0,1 };
		GLfloat mat2_specular[4] = { 0.6,0.6,0.6,1 };
		GLfloat mat2_shininess = 32.0;
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat2_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat2_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat2_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, mat2_shininess);

		vector<int> numarr;
		numarr.clear();
		int temp = score;
		do
		{
			numarr.push_back(temp % 10);
			temp /= 10;
		} while (temp != 0);
		for (int i = numarr.size() - 1,j=0; i >= 0; i--,j++)
		{
			glPushMatrix();
			glLineWidth(5);
			glTranslated(-0.5+j*0.03, -0.5, -1);
			glScaled(0.003, 0.003, 0.003);
			pScore.PrintNum(numarr[i]);
			glPopMatrix();
		}
	glPopMatrix();

	/*Print the title of the "LIFE"*/
	glPushMatrix();
	GLfloat mat3_ambient[4] = { 0,0.0,0,1 };
	GLfloat mat3_diffuse[4] = { 0,0,0,1 };
	GLfloat mat3_specular[4] = { 0.6,0.6,0.6,1 };
	GLfloat mat3_shininess = 32.0;
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat3_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat3_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat3_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat3_shininess);

	strcpy(str, "LIFE");
	glLineWidth(5);
	glTranslated(0.25, -0.5, -1);
	glScaled(0.003, 0.003, 0.003);
	pScore.PrintStr(str);
	glPopMatrix();

	//Print the Value of the Life
	glPushMatrix();
		GLfloat mat4_ambient[4] = { 0,0.0,0,1 };
		GLfloat mat4_diffuse[4] = { 0,0,0,1 };
		GLfloat mat4_specular[4] = { 0.6,0.6,0.6,1 };
		GLfloat mat4_shininess = 32.0;
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat4_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat4_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat4_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, mat4_shininess);

		numarr.clear();
		temp = life;
		do
		{
			numarr.push_back(temp % 10);
			temp /= 10;
		} while (temp != 0);
		for (int i = numarr.size() - 1, j = 0; i >= 0; i--, j++)
		{
			glPushMatrix();
			glLineWidth(5);
			glTranslated(0.4 + j * 0.03, -0.5, -1);
			glScaled(0.003, 0.003, 0.003);
			pScore.PrintNum(numarr[i]);
			glPopMatrix();
		}
	glPopMatrix();

}

void Draw3DSGrid()
{
	// This function was added to give a better feeling of moving around.
	// A black background just doesn't give it to ya :)  We just draw 100
	// green lines vertical and horizontal along the X and Z axis.

	// Turn the lines GREEN



	// Draw a 1x1 grid along the X and Z axis'
	for (float i = -25,j=0; i <= 25; i += 1,j+=0.01)
	{
		GLfloat mat_ambient[4] = { 0.5,0.5,j,1 };
		GLfloat mat_diffuse[4] = { 0.8-j,0.8,0.8,1 };
		GLfloat mat_specular[4] = { 0.6,0.6,0.6,1 };
		GLfloat mat_shininess = 32.0;
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

		// Start drawing some lines
		glBegin(GL_QUAD_STRIP);
		
		// Do the horizontal lines (along the X)
		glVertex3f(-25, 0, i);
		glVertex3f(25, 0, i);

		// Do the vertical lines (along the Z)
		glVertex3f(i, 0, -25);
		glVertex3f(i, 0, 25);

		// Stop drawing lines
		glEnd();
	}

}

void PrintScore()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_LIGHT0);

	/******setting*******/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, 0, 25);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 6, 0, 0, 0, 0, 1, 0);

	char str[] = "SCORE ";

	glPushMatrix();
	glTranslated(-80, 0, 0);
		pScore.PrintStr(str);
	glPopMatrix();

	glPushMatrix();
	vector<int> numarr;
	glColor3d(1, 1, 1);
	numarr.clear();
	int temp = score;
	do
	{
		numarr.push_back(temp % 10);
		temp /= 10;
	} while (temp != 0);
	for (int i = numarr.size() - 1, j = 0; i >= 0; i--, j++)
	{
		glPushMatrix();
		glTranslated(0 + 10 * j, 0, 0);
		pScore.PrintNum(numarr[i]);
		glLoadIdentity();
		glPopMatrix();
	}
	glPopMatrix();
}

void DrawFruit()
{
	
	for (int i = 0; i<myfruit.size(); i++)
		if (myfruit[i].isalive)
		{
			glPushMatrix();
			myfruit[i].Draw();
			glPopMatrix();
		}
}


void GameMode()
{
	/******setting*******/
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); // Modeling transformation
	glLoadIdentity();

	/********************Texture*****************************/
	
	glEnable(GL_DEPTH_TEST); // We enable the depth test (also called z buffer)
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat position0[4] = { 0,60,0,1.0f };
	GLfloat ambient0[4] = { 0.4,0.4,0.2,1 };
	GLfloat diffuse0[4] = { 1,1,1,1 };
	GLfloat specular0[4] = { 1,1,1,1 };
	glLightfv(GL_LIGHT0, GL_POSITION, position0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);

	/*********************/

	myCamera.Look();

	glPushMatrix();
		DrawInterFace();
	glPopMatrix();

	glPushMatrix();
		DrawFruit();
	glPopMatrix();

	glPushMatrix();
		CreatWorld();
	glPopMatrix();
}


void mydisplay()
{

	if (life > 0)
		GameMode();
	else
		PrintScore();

	glutSwapBuffers();
	glFlush();
}

void mykeyboard(unsigned char key, int x, int y)
{
	if(GetKeyState('Z')&0x80)life = 0;
	if (GetKeyState('Q') & 0x80)exit(0);
	//if (key == 'q' || key=='Q') exit(0);
	//if (key == 'z'||key=='Z') life = 0;
	glutPostRedisplay();
}

void FruitDrop()
{

	for (int i = 0; i < myfruit.size(); i++)
	{
		glPushMatrix();
		myfruit[i].Update();
		glPopMatrix();
	}

	Vector3 tcam = myCamera.Position();
	for (int i = 0; i < myfruit.size(); i++)
	{
		if (tcam.Distance(myfruit[i].Position()) < (myfruit[i].GetRadius()+1.0) && myfruit[i].isalive)
		{
			if (myfruit[i].type == 0)
				score++;
			else if (myfruit[i].type == 1)
				score += 3;
			else if (myfruit[i].type == 2)
				score += 5;
			else if (myfruit[i].type == 3)
			{
				score -= 20;
				if (score < 0) score = 0;
				life-=2;
			}
			else score += 10;

			myfruit[i].isalive = 0;
			myfruit[i].ResetRandomFruit(BallHeight + Interval*i);
		}
	}

	for (int i = 0; i < myfruit.size(); i++)
	{
		Vector3 pos = myfruit[i].Position();
		if (pos.y < -5 && myfruit[i].isalive && myfruit[i].type!=3)
		{
			myfruit[i].isalive = 0;
			myfruit[i].ResetRandomFruit(BallHeight + Interval * i);
			life--;
		}
		else if(pos.y < -5 && myfruit[i].isalive && myfruit[i].type == 3)
		{
			myfruit[i].isalive = 0;
			myfruit[i].ResetRandomFruit(BallHeight + Interval * i);
		}
	}

	bool check = 1;
	for (int i = 0; i < myfruit.size(); i++)
	{
		if (myfruit[i].isalive) check = 0;
	}

	if (check)
	{
		for (int i = 0; i < myfruit.size(); i++)
		{
			myfruit[i].isalive = 1;
		}

		if (myfruit.size()-5 < (score / 10))
		{
			Fruit fr(Vector3(rand() % 25 - 50, 0, rand() % 25 - 50));
			fr.ResetRandomFruit(BallHeight + Interval * myfruit.size());
			myfruit.push_back(fr);
		}
	}

}

void myidle()
{
	cout << score<< " " << life << endl;
	if (life > 0)
	{
		myCamera.Update();

		FruitDrop();

		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Parm's Program");
	init();
	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(mykeyboard);
	glutIdleFunc(myidle);
	glutMainLoop();
}
