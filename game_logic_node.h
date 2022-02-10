#pragma once
#include <gl/glut.h>
#include"golbal_variables.h"
#include"glstring_topic.h"
#include"game_logic_topic.h"

void initialCar()
{
	int yyy;
	double r, b, g;

	for (int i = 0; i < 100; i++)
	{
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		r /= 255; g /= 255; b /= 255;
		car[i].colorRED = r;
		car[i].colorGREEN = g;
		car[i].colorBLUE = b;
		yyy = rand() % 6;
		yyy -= 3;
		car[i].pointX = yyy;
		car[i].pointY = 1.5 * (i + 3);
		car[i].setVisible = true;

	}

}




void init() {
	//set missile visibility false
	for (int i = 0; i < 4; i++)
	{
		m[i].setVisible = false;
	}
	//create color box
	//initialCar();



	// set clear color to black
	glClearColor(0.08, 0.08, 0.08, 0.0);

	// set fill color to white
	glColor3d(1.0, 1.0, 1.0);

	//set up standard orthogonal view with clipping
	//box as cube of side 2 centered at origin
	//This is the default view and these statements could be removed
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-4.0, 6.0, -3.0, 3.0);
	makeRasterFont();

}


void updateSpeed()
{
	if (carSpeed < 0.05) {
		if (carSpeedCounter > carSpeed)
		{
			carSpeed += 0.001;
			carSpeedCounter = 0.0;
		}
		carSpeedCounter += 0.0002;
	}
}

void update(int value) {
	for (int i = 0; i < 100; i++)
	{
		car[i].pointY -= carSpeed;

	}
	roadCounter -= 2 * carSpeed;
	if (roadCounter < -3.5)
	{
		roadCounter = 0.5;
		point++;
		if (isRoadEmpty())
		{
			initialCar();
		}
	}
	glutPostRedisplay(); //Tell GLUT that the display has changed
	for (int i = 0; i < 4; i++)
	{
		if (m[i].setVisible)
		{
			m[i].pointY += 0.03;
		}
	}
	//missilePointY+=.03;
	//check collition
	if (isCarCollusion())
	{
		life -= 10;
		carSpeed /= 2;

	}


	isMissileCollusion();

	updateSpeed();
	if (missileCounter < 2) {
		missileCounter += 0.0005;
	}
	if (isGameOver())
		return;
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(gameSpeed, update, 0);

}


