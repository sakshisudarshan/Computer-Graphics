#include <stdio.h>
#include <GL/glut.h>
#include<math.h>

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void draw_h(float P[9][2]) {
	glBegin(GL_LINE_LOOP);
	glVertex2fv(P[0]);
	glVertex2fv(P[1]);
	glVertex2fv(P[2]);
	glVertex2fv(P[3]);
	glVertex2fv(P[4]);
	glEnd();
	glBegin(GL_LINES);
	glVertex2fv(P[1]);
	glVertex2fv(P[3]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2fv(P[5]);
	glVertex2fv(P[6]);
	glVertex2fv(P[7]);
	glVertex2fv(P[8]);
	glEnd();
	
}

void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	float fpx = 20, fpy = 40, theta = 30;
	float PI[9][2] = { {10,10},{10,30},{25,40},{40,30},{40,10},{20,10},{20,20},{30,20},{30,10} };
	glColor3f(1, 0, 0);
	draw_h(PI);
	glFlush();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(fpx, fpy, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-fpx, -fpy, 0);
	glColor3f(0, 1, 0);
	draw_h(PI);
	glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 20);
	glutCreateWindow("house");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
    return 0;
}
