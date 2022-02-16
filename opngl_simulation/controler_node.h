#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <gl/glut.h>

#include"golbal_variables.h"
#include"drawing_node.h"
#include"glstring_topic.h"

void keyboardown(int key, int xx, int yy)
{
	switch (key) {
	case GLUT_KEY_RIGHT:
		if (posX < 2)
			posX += move_unit;
		break;

	case GLUT_KEY_LEFT:
		if (posX > -3)
			posX -= move_unit;
		break;

	case GLUT_KEY_UP:
		if (posY < 2)
			posY += move_unit;
		break;

	case GLUT_KEY_DOWN:
		if (posY > -3)
			posY -= move_unit;
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

void display() {
	//Clear Window
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawRoad();
	drawEnemy();

	drawMissile();
	glPushMatrix();
	glTranslated(posX, posY, posZ);

	drawCar(.5, .5, .5);

	glPopMatrix();


	printText();

	glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
	double move_unit = 1.0f;
	switch (key) {
	case ' ':
		if (missileCounter > 0.50)
		{
			missileCounter -= 0.50;
			for (int i = 0; i < 4; i++)
			{
				if (!m[i].setVisible)
				{
					m[i].pointX = posX;
					m[i].pointY = posY;
					m[i].setVisible = true;
					break;
				}
			}
		}
		break;


	default:
		break;
	}
	glutPostRedisplay();
}
