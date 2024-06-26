#include<GL/glut.h>
#include<math.h>

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

void eightway(float x, float y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glVertex2f(-y, x);
	glVertex2f(-x, y);
	glVertex2f(-x, -y);
	glVertex2f(-y, -x);
	glVertex2f(y, -x);
	glVertex2f(x, -y);
	glVertex2f(y, x);
	glEnd();
	glFlush();
}

void display() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	float x, y, r = 75, th;
	for (th = 0; th <= 45; th += 0.5) {
		x = r * cos(th) + 100;
		y = r * sin(th) + 100;
		eightway(x, y);
	}
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("EightWaySymmetry");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
    return 0;
}
