#include <GL/glut.h>
#include <math.h>

float th = 0;
float r = 50;

void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    float x = r * cos(th * M_PI / 180.0);  
    float y = r * sin(th * M_PI / 180.0); 
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(-y,x);  
    glVertex2f(-x,-y);
    glVertex2f(y,-x);
    glEnd();
    glutSwapBuffers();
   
}

void idle() {
    th += 5;
    if (th >= 360)
        th = 0;
    glutPostRedisplay();
}

void mouse(int b, int s, int x, int y) {
    if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN) {
        glutIdleFunc(idle);
    }
    if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN) {
        glutIdleFunc(NULL);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Eight-Way Symmetry");
    myinit();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
