#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <gl/glut.h>
#pragma once

#include"controler_node.h"

void reshape(int width, int heigth) {
	/* window ro reshape when made it bigger or smaller*/

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//clip the windows so its shortest side is 2.0
	if (width < heigth) {
		glOrtho(-2.0, 2.0, -2.0 * (GLdouble)heigth / (GLdouble)width, 2.0 * (GLdouble)heigth / (GLdouble)width, 2.0, 2.0);
	}
	else {
		glOrtho(-2.0, 2.0, -2.0 * (GLdouble)width / (GLdouble)heigth, 2.0 * (GLdouble)width / (GLdouble)heigth, 2.0, 2.0);
	}
	// set viewport to use the entire new window
	glViewport(0, 0, width, heigth);
}

void rect() {
	glBegin(GL_POLYGON);

	glVertex2d(0.0, 0.0);
	glVertex2d(0.0, 1.0);
	glVertex2d(1.0, 1.0);
	glVertex2d(1.0, 0.0);
	glEnd();
}

void drawArc(int start, double end, double radiusX, double radiusY, double positionX, double positionY)
{
	for (int i = start; i < end; i++)
	{
		double rad = i * DEG2RAD;
		glVertex2d(positionX + cos(rad) * radiusX,
			positionY + sin(rad) * radiusY);
	}
}

void drawCar(double r, double g, double b)
{


	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	drawArc(230, 313, .24, .11, .49, .13);
	glVertex2d(.70, .23);
	glVertex2d(.69, .43);
	glVertex2d(.69, .71);
	drawArc(-17, 198, .21, .17, .49, .76);
	glVertex2d(.29, .71);
	glVertex2d(.29, .43);
	glVertex2d(.28, .23);
	glEnd();
	////
	glLineWidth(1.5);
	glColor3d(r / 5, g / 5, b / 5);
	glBegin(GL_LINE_LOOP);
	drawArc(230, 313, .24, .11, .49, .13);
	glVertex2d(.70, .23);
	glVertex2d(.69, .43);
	glVertex2d(.69, .71);
	drawArc(-17, 198, .21, .17, .49, .76);
	glVertex2d(.29, .71);
	glVertex2d(.29, .43);
	glVertex2d(.28, .23);

	glEnd();
	glLineWidth(1.0);
	////////////////////////
	glColor3d(r / 1.5, g / 1.5, b / 1.5);
	glBegin(GL_POLYGON);
	glVertex2d(.61, .53);
	drawArc(52, 129, .25, .28, .49, .44);
	glVertex2d(.37, .53);
	glEnd();
	glColor3d(r / 3, g / 3, b / 3);
	glBegin(GL_LINE_LOOP);
	glVertex2d(.61, .53);
	drawArc(52, 129, .25, .28, .49, .44);
	glVertex2d(.37, .53);
	glEnd();
	////////
	glColor3d(r / 1.5, g / 1.5, b / 1.5);
	glBegin(GL_POLYGON);
	glVertex2d(.38, .23);
	//drawArc(181,359,12,7,49,16);
	drawArc(-134, -45, .15, .18, .49, .27);
	glVertex2d(.60, .23);
	glEnd();
	glColor3d(r / 3, g / 3, b / 3);
	glBegin(GL_LINE_LOOP);
	glVertex2d(.38, .23);
	//drawArc(181,359,12,7,49,16);
	drawArc(-134, -45, .15, .18, .49, .27);
	glVertex2d(.60, .23);
	glEnd();
	///////////
	glColor3d(r / 1.5, g / 1.5, b / 1.5);
	glBegin(GL_POLYGON);
	glVertex2d(.31, .31);
	drawArc(348, 390, .25, .42, .11, .36);
	glEnd();
	glColor3d(r / 3, g / 3, b / 3);
	glBegin(GL_LINE_LOOP);
	glVertex2d(.31, .31);
	drawArc(348, 390, .25, .42, .11, .36);
	glEnd();
	/////////////
	glColor3d(r / 1.5, g / 1.5, b / 1.5);
	glBegin(GL_POLYGON);
	glVertex2d(.67, .30);
	drawArc(151, 194, .25, .42, .87, .36);
	glEnd();
	glColor3d(r / 3, g / 3, b / 3);

	glBegin(GL_LINE_LOOP);
	glVertex2d(.67, .30);
	drawArc(151, 194, .25, .42, .87, .36);
	glEnd();


}

void drawRoad()
{// gluOrtho2D(-4.0, 4.0, -3.0, 3.0);
	glPushMatrix();
	glTranslated(0, 0, 0);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glVertex2d(-4, -3);
	glVertex2d(-4, 3);
	glVertex2d(-3, 3);
	glVertex2d(-3, -3);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glVertex2d(3, -3);
	glVertex2d(3, 3);
	glVertex2d(4, 3);
	glVertex2d(4, -3);
	glEnd();


	glColor3d(1, 1, 1);
	double x = 0;
	glBegin(GL_POLYGON);
	glVertex2d(x + 0.0625, 5.5 + roadCounter);
	glVertex2d(x + 0.0625, 3.5 + roadCounter);
	glVertex2d(x - 0.0625, 3.5 + roadCounter);
	glVertex2d(x - 0.0625, 5.5 + roadCounter);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2d(x + 0.0625, 1.5 + roadCounter);
	glVertex2d(x + 0.0625, -0.5 + roadCounter);
	glVertex2d(x - 0.0625, -0.5 + roadCounter);
	glVertex2d(x - 0.0625, 1.5 + roadCounter);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2d(x + 0.0625, -2.5 + roadCounter);
	glVertex2d(x + 0.0625, -4.5 + roadCounter);
	glVertex2d(x - 0.0625, -4.5 + roadCounter);
	glVertex2d(x - 0.0625, -2.5 + roadCounter);
	glEnd();

	////////////////
	glTranslated(4.0, -2.5, 0.0);
	//life bar
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glVertex2d(0.625, 2);
	glVertex2d(0.625, 0.0);
	glVertex2d(0.375, 0.0);
	glVertex2d(0.375, 2);
	glEnd();
	if (life > 50)
	{
		glColor3d(0.02 * (100 - life), 1, 0.0);
	}
	else
	{
		glColor3d(1, 0.02 * life, 0);
	}
	glBegin(GL_POLYGON);

	glVertex2d(0.625, 0.02 * life);
	glVertex2d(0.625, 0.0);
	glVertex2d(0.375, 0.0);
	glVertex2d(0.375, 0.02 * life);
	glEnd();
	//glColor3f(0.1,0.0,0.8);

	//speed bar
	glBegin(GL_POLYGON);
	glColor3d(0.15, 0.15, 0.15);
	glVertex2d(1.625, 2);
	glVertex2d(1.625, 0.0);
	glVertex2d(1.375, 0.0);
	glVertex2d(1.375, 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(1, 1 - 20 * carSpeed, 0);
	glVertex2d(1.625, 40 * carSpeed);
	glColor3d(1, 1, 0);
	glVertex2d(1.625, 0.0);
	glVertex2d(1.375, 0.0);
	glColor3d(1, 1 - 20 * carSpeed, 0);
	glVertex2d(1.375, 40 * carSpeed);
	glEnd();
	///////////////

	glBegin(GL_POLYGON);
	glColor3d(0.15, 0.15, 0.15);
	glVertex2d(0.375, 2.5);
	glVertex2d(0.375, 3);
	glVertex2d(1.625, 3);
	glVertex2d(1.625, 2.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3d(0.15, 0.15, 0.45);
	glVertex2d(0.375, 2.5);
	glVertex2d(0.375, 3);
	glVertex2d(0.375 + 0.625 * missileCounter, 3);
	glVertex2d(0.375 + 0.625 * missileCounter, 2.5);
	glEnd();
	glPopMatrix();


}
void drawEnemy()
{

	for (int i = 0; i < 100; i++)
	{
		if (car[i].setVisible)
		{
			if (car[i].pointY<3 && car[i].pointY>-4) {
				glPushMatrix();
				glTranslated(car[i].pointX, car[i].pointY, 0);
				drawCar(car[i].colorRED, car[i].colorGREEN, car[i].colorBLUE);
				glPopMatrix();
			}
			if (car[i].pointY <= -4)
				car[i].setVisible = false;
		}
	}
}
void drawMissile()
{
	for (int i = 0; i < 4; i++)
	{
		if (m[i].setVisible)
		{
			if (m[i].pointY < 3)
			{
				glPushMatrix();
				glTranslated(m[i].pointX, m[i].pointY, 0);
				glBegin(GL_POLYGON);
				glColor3d(1, 0, 0);
				drawArc(0, 181, .04, .1, 0.49, 0.53);
				glEnd();
				glBegin(GL_POLYGON);
				glColor3d(1, 1, 1);
				glVertex2d(.45, 0.53);
				glVertex2d(.53, .53);
				glVertex2d(.53, .23);
				glVertex2d(.45, .23);
				glEnd();
				glPopMatrix();
			}
			else
			{
				m[i].setVisible = false;
			}

		}
	}
}
