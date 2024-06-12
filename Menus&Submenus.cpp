#include<GL/glut.h>
#include<math.h>

int r = 0, g = 0, b = 0;

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glEnd();
	glFlush();
}

void sub_menu(int choice) {
	switch (choice) {
	case 1: r = 1;
		g = 0;
		b = 0;
		break;
	case 2: r = 0;
		g = 1;
		b = 0;
		break;
	case 3: r = 0;
		g = 0;
		b = 1;
		break;
	default: return;
	}
	glutPostRedisplay();
}

void main_menu(int choice) {
	switch (choice) {
	case 1: exit(0);
	default: return;
	}
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Menus");
	myinit();
	glutDisplayFunc(display);
	int menu = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutCreateMenu(main_menu);
	glutAddSubMenu("Color", menu);
	glutAddMenuEntry("Quit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
    return 0;
}
