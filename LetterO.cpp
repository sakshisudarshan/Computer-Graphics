#include<GL/glut.h>
#include<math.h>
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 110, 0, 110);
	glMatrixMode(GL_MODELVIEW);
}
void draw(int r)
{
	for (int i = 0; i <= 360; i++)
	{
		glVertex2d(50 + r * cos(i), 50 + r * sin(i));
	}
}
void display1()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	draw(40);
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("O LETTER");
	myinit();
	glutDisplayFunc(display1);
	glutMainLoop();
    return 0;
}
