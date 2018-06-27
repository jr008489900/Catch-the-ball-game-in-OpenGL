#include<cstring>
#include<vector>
#include "Text.h"
#include<GL\glut.h>
using namespace std;

Text::Text()
{
}

void Text::PrintChar(char ch)
{
	glLineWidth(3);
	glBegin(GL_LINES);
	switch (ch)
	{
	case '0':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;

	case '1':
		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;

	case '2':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;

	case '3':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;

	case '4':
		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;

	case '5':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);
		break;

	case '6':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);
		break;

	case '7':

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;

	case '8':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;

	case '9':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;
	case 'T':
		glVertex3d(0, 10, 0);
		glVertex3d(10, 10, 0);

		glVertex3d(5, 10, 0);
		glVertex3d(5, 0, 0);
		break;
	case 'I':
		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(2.5, 10, 0);
		glVertex3d(2.5, 0, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);
		break;

	case'M':
		glVertex3d(0, 0, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(10, 10, 0);

		glVertex3d(10, 10, 0);
		glVertex3d(10, 0, 0);
		break;
	case 'E':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);
		break;

	case'S':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);
		break;

	case 'C':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);
		break;

	case 'O':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;
	case'R':
		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(7, 0, 0);
		break;
	case 'G':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(2, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);
		break;

	case 'A':

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 5, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(5, 5, 0);
		glVertex3d(5, 10, 0);
		break;

	case'V':
		glVertex3d(0, 10, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(5, 0, 0);
		glVertex3d(10, 10, 0);
		break;

	case'L':
		glVertex3d(0, 0, 0);
		glVertex3d(5, 0, 0);

		glVertex3d(0, 0, 0);
		glVertex3d(0, 10, 0);
		break;

	case'F':
		glVertex3d(0, 0, 0);
		glVertex3d(0, 10, 0);

		glVertex3d(0, 5, 0);
		glVertex3d(5, 5, 0);

		glVertex3d(0, 10, 0);
		glVertex3d(5, 10, 0);
		break;

	default:
		break;
	}
	glEnd();
}

void Text::PrintNum(int num)
{

		glBegin(GL_LINES);
		switch (num)
		{
		case 0:
			glVertex3d(0, 0, 0);
			glVertex3d(5, 0, 0);

			glVertex3d(0, 10, 0);
			glVertex3d(5, 10, 0);

			glVertex3d(0, 0, 0);
			glVertex3d(0, 5, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(0, 10, 0);

			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(5, 5, 0);
			glVertex3d(5, 10, 0);
			break;

		case 1:
			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(5, 5, 0);
			glVertex3d(5, 10, 0);
			break;

		case 2:
			glVertex3d(0, 0, 0);
			glVertex3d(5, 0, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(0, 10, 0);
			glVertex3d(5, 10, 0);

			glVertex3d(0, 0, 0);
			glVertex3d(0, 5, 0);

			glVertex3d(5, 5, 0);
			glVertex3d(5, 10, 0);
			break;

		case 3:
			glVertex3d(0, 0, 0);
			glVertex3d(5, 0, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(0, 10, 0);
			glVertex3d(5, 10, 0);

			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(5, 5, 0);
			glVertex3d(5, 10, 0);
			break;

		case 4:
			glVertex3d(0, 5, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(0, 10, 0);

			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(5, 5, 0);
			glVertex3d(5, 10, 0);
			break;

		case 5:
			glVertex3d(0, 0, 0);
			glVertex3d(5, 0, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(0, 10, 0);
			glVertex3d(5, 10, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(0, 10, 0);

			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);
			break;

		case 6:
			glVertex3d(0, 0, 0);
			glVertex3d(5, 0, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(0, 0, 0);
			glVertex3d(0, 5, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(0, 10, 0);

			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);
			break;

		case 7:

			glVertex3d(0, 10, 0);
			glVertex3d(5, 10, 0);

			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(5, 5, 0);
			glVertex3d(5, 10, 0);
			break;

		case 8:
			glVertex3d(0, 0, 0);
			glVertex3d(5, 0, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(0, 10, 0);
			glVertex3d(5, 10, 0);

			glVertex3d(0, 0, 0);
			glVertex3d(0, 5, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(0, 10, 0);

			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(5, 5, 0);
			glVertex3d(5, 10, 0);
			break;

		case 9:
			glVertex3d(0, 0, 0);
			glVertex3d(5, 0, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(0, 10, 0);
			glVertex3d(5, 10, 0);

			glVertex3d(0, 5, 0);
			glVertex3d(0, 10, 0);

			glVertex3d(5, 0, 0);
			glVertex3d(5, 5, 0);

			glVertex3d(5, 5, 0);
			glVertex3d(5, 10, 0);
			break;

		default:
			break;
		}
		glEnd();

}

void Text::PrintStr(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		glPushMatrix();
		glTranslated( i * 10, 0, 0);
		PrintChar(str[i]);
		glPopMatrix();
	}
}

Text::~Text()
{
}
