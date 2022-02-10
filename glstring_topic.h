#pragma once
#include<string.h>
#include <gl/glut.h>
#include"golbal_variables.h"
void makeRasterFont(void)
{
	GLuint i, j;
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	fontOffset = glGenLists(128);
	for (i = 0, j = 'A'; i < 26; i++, j++) {
		glNewList(fontOffset + j, GL_COMPILE);
		glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, letters[i]);
		glEndList();
	}

	for (i = 0, j = '0'; i < 10; i++, j++) {
		glNewList(fontOffset + j, GL_COMPILE);
		glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, numbers[i]);
		glEndList();
	}


	glNewList(fontOffset + ' ', GL_COMPILE);
	glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
	glEndList();
}
void printString(char* s)
{
	glPushAttrib(GL_LIST_BIT);
	glListBase(fontOffset);
	glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte*)s);
	glPopAttrib();
}

void printText()
{
	char buffer[10];
	char str[80];
	int missile = int(missileCounter * 2);
	//print score
	glPushMatrix();
	glTranslated(4.5, 2, 0);
	glColor3d(1, 1, 1);
	glRasterPos2i(0, 0);

	sprintf(buffer, "%d", point);
	strcpy(str, " Pass: ");
	strcat(str, buffer);
	printString(str);
	glPopMatrix();
	///
	glPushMatrix();
	glTranslated(4.25, -2.7, 0);
	glColor3d(1, 1, 1);
	glRasterPos2i(0, 0);
	//printString("LIFE SPEED");
	glPopMatrix();

	glPushMatrix();
	glTranslated(4.44, 0.20, 0);
	glColor3d(1, 1, 1);
	glRasterPos2i(0, 0);
	sprintf(buffer, "%d", missile);
	strcpy(str, " Colloison ");
	strcat(str, buffer);
	printString(str);
	glPopMatrix();

}

