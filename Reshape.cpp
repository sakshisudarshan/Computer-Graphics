#include <stdio.h>
#include <GL/glut.h>

int reshapeCount = 0;

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void display1() {
	glClearColor(1,1,1,1); 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0); 
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5); 
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush(); 
}

void myReshape(int w, int h) {
	reshapeCount++; 
	printf("Reshape function called %d times\n", reshapeCount);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) {
		gluOrtho2D(-1.0 * float(w) / float(h), 1.0 * float(w) / float(h), -1.0, 1.0);
	}
	else {
		gluOrtho2D(-1.0, 1.0, -1.0 * float(h) / float(w), 1.0 * float(h) / float(w));
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay(); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("First");
	myinit(); 
	glutDisplayFunc(display1); 
	glutReshapeFunc(myReshape);
	glutMainLoop(); 
    return 0;
}
