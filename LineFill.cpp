#include<GL/glut.h>
#include<math.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glPointSize(50);
	glVertex2d(x, y);
	glEnd();
	glFlush();
}
void bres(int x0, int y0, int x1, int y1)
{
	int dx = fabs(x1 - x0), dy = fabs(y1 - y0);
	int p = 2 * dy - dx;
	int a = 2 * dy, b = 2 * (dy - dx);
	int x, y;
	if (x0 > x1) {
		x = x1;
		y = y1;
		x1 = x0;
	}
	else {
		x = x0;
		y = y0;
	}
	plot(x, y);
	while (x < x1) {
		x++;
		if (p < 0)
			p += a;
		else {
			y++;
			p += b;
		}
		plot(x, y);
	}
}
void display1()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	for (int i = 0; i < 100; i++)
	{
		bres(100, 100 + i, 400, 100 + i);
	}

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("LINE FILL");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();
    return 0;
}
