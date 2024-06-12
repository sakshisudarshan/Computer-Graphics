#include <stdio.h>
#include <GL/glut.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display1() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 10);
	glVertex2f(10, 60);
	glVertex2f(60, 60);
	glVertex2f(60, 10);
	glEnd();
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(10, 60);
	glVertex2f(35, 90);
	glVertex2f(60, 60);
	glEnd();
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(30, 10);
	glVertex2f(30, 30);
	glVertex2f(40, 30);
	glVertex2f(40, 10);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 20);
	glutCreateWindow("First");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();
    return 0;
}
