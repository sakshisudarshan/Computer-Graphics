#include<GL/glut.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 110, 0, 110);
	glMatrixMode(GL_MODELVIEW);
}
void display1()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(40, 100);
	glVertex2d(60, 20);
	glVertex2d(10, 70);
	glVertex2d(70, 70);
	glVertex2d(20, 20);
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Star");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();
    return 0;
}
