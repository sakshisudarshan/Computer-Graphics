#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

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
	glColor3f(1, 0.5, 0.5);
	glBegin(GL_POINTS);
	float theta = 0;
	float r = 10;
	
		for (theta = 0; theta <= 360; theta += 0.1)
		{

			float x = r * cos(theta) + 50;
			float y = r * sin(theta) + 50;
			glVertex2f(x, y);

		}
	
	glEnd();
	glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 20);
	glutCreateWindow("circle");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();
    return 0;
}
