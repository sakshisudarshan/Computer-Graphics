#include<cmath>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/gl.h>

int wh = 500;
int ww = 500;
int r = 0, g = 1, b = 0;
int k;

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}
void display() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void draw(int x, int y, char shape) {
	y = wh - y;
	glColor3f(r, g, b);
	switch (shape) {
	case 'S':
		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
		glVertex2f(20, 20);
		glVertex2f(40, 20);
		glVertex2f(40, 40);
		glVertex2f(20, 40);
		glEnd();
		glFlush();
		break;
	case 'R':

		glBegin(GL_POLYGON);
		glVertex2f(20, 40);
		glVertex2f(30, 40);
		glVertex2f(30, 60);
		glVertex2f(20, 60);
		glEnd();
		glFlush();
		break;

	case 'T':
		glBegin(GL_POLYGON);
		glVertex2f(50, 50);
		glVertex2f(65, 80);
		glVertex2f(80, 50);
		glEnd();
		glFlush();
		break;
	case 'C':
		glBegin(GL_POINTS);
		int r = 70;
		int theta, x, y;
		for (theta = 0; theta <= 360; theta += 1)
		{
			x = r * cos(theta);
			y = r * sin(theta);
			glVertex2f(x, y);

		}
		glEnd();
		glFlush();
		break;
	}
	glutPostRedisplay();
}

void mykey(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'S': k = key;
		draw(x, y, k);
		break;

	case 'R': k = key;
		draw(x, y, k);
		break;
	case 'T':k = key;
		draw(x, y, key);
		break;
	case 'C':k = key;
		draw(x, y, key);
		break;
	case 'Q':k = key;
		exit(0);
		break;
	case 'r': r = 1; g = 0; b = 0;
		draw(x, y, k);
		break;
	case 'g': r = 0; g = 1; b = 0;
		draw(x, y, k);
		break;
	case 'b': r = 0; g = 0; b = 1;
		draw(x, y, k);
		break;
	}
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("third");
	myinit();
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	glutMainLoop();
    return 0;
}
