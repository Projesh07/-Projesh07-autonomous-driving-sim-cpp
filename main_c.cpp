#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <gl/glut.h>

#include"controler_node.h"
#include"game_logic_node.h"
#include"objects_topic.h"
#include"drawing_node.h"
#include"glstring_topic.h"
#include"game_logic_topic.h"
/

int main(int argc, char** argv) {
	
	//-- creating window

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Car Game");
	//start:
	glutDisplayFunc(display);
	init();
	// keyboard control
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardown);
	glutTimerFunc(2000, update, 0); //Add a timer
	glutMainLoop();
}
