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

void setPixel(int x, int y) {
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
	glFlush();
}

void lineBres(int x0, int y0, int xend, int yend) {
	int dx = fabs(xend - x0), dy = (yend - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusdx = 2 * (dy - dx);
	int x, y;
	if (x0 > xend) {
		x = xend;
		y = yend;
		xend = x0;
	}
	else {
		x = x0;
		y = y0;
	}

	setPixel(x, y);
	while (x < xend) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p+= twoDyMinusdx;
		}
		setPixel(x, y);
	}
}

void display1() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	float x1 = 8, x0 = 5, y1 = 13, y0 = 8;
	lineBres(x0, y0, x1, y1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 20);
	glutCreateWindow("BresAlg");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();
    return 0;
}
