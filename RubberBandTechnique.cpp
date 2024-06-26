#include<GL/glut.h>
#include<math.h>

int f = 0;
int xm, ym, xmm, ymm;
int ww = 500, wh = 500;

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_COLOR_LOGIC_OP);
}

void mouse(int b, int s, int x, int y) {
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN) {
		f = 0;
		xm = x;
		ym = wh - y;
		glColor3f(1, 0, 0);
	}
	if (b == GLUT_LEFT_BUTTON && s == GLUT_UP) {
		glRectf(xm, ym, xmm, ymm);
		glFlush();
		glColor3f(0, 1, 0);
		glLogicOp(GL_COPY);
		xmm = x;
		ymm = wh - y;
		glLogicOp(GL_XOR);
		glRectf(xm, ym, xmm, ymm);
		glFlush();
	}
}

void move(int x, int y) {
	if (f == 1) {
		glLogicOp(GL_XOR);
		glRectf(xm, ym, xmm, ymm);
		glFlush();
	}
	xmm = x;
	ymm = wh - y;
	glRectf(xm, ym, xmm, ymm);
	glFlush();
	f = 1;
}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("Rubberbanding");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(move);
	glutMainLoop();
    return 0;
}
