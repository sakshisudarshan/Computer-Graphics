#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void plot_pixel(float x, float y) {
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
void linedda(float x0, float y0, float x1, float y1)
{
	float dx = x1 - x0, dy = y1 - y0, xincr, yincr;
	int steps, i;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xincr = dx / steps;
	yincr = dy / steps;
	float x = x0;
	float y = y0;
	plot_pixel(round(x), round(y));
	for (i = 0; i < steps; i++)
	{
		x = x + xincr;
		y = y + yincr;
		plot_pixel(round(x), round(y));
	}

}

void display1() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	float x1 = 8, x0 = 5, y1 = 13, y0 = 8;
	linedda(x0, y0, x1, y1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 20);
	glutCreateWindow("Dda");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();
    return 0;
}
