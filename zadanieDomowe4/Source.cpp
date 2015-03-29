#include <iostream>
#include <math.h>
#include "func.h"
#define PI 3.14159265

#include <GL/freeglut.h>



static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void idle(void)
{
	glutPostRedisplay();
}


int main(int argc, char *argv[])
{
	
	printf("Hello openGL world!");


	glutInitWindowSize(1200, 600);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");

	inicjacja1();
	inicjacja2();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(&sterowanie);

	// set white as the clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();

	return 0;
}