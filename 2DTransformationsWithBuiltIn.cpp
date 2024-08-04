#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float th= 0.0;
float s= 1.0;
float tx = 0.0;
float ty = 0.0;


void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); 

    glTranslatef(tx, ty, 0.0);
    glScalef(s, s, 1.0); 
    glRotatef(th, 0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-5.0, -5.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(5.0, -5.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0, 5.0);
    glEnd();
    
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
           th += 5.0;
            break;
        case 'd':
            th -= 5.0;
            break;
        case 'w':
            s += 0.1;
            break;
        case 's':
            if (s > 0.1) 
                s -= 0.1;
            break;
        case 'i':
            ty += 0.5;
            break;
        case 'k':
            ty -= 0.5;
            break;
        case 'j':
            tx -= 0.5;
            break;
        case 'l':
            tx += 0.5;
            break;
        case 27: 
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D Geometric Operations using builtin functions");
    myinit();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
