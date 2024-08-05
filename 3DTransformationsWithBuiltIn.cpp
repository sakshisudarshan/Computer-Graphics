#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float V[8][3] = {
   {-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}
};

float C[8][3] = {
  {0,0,1},{0,1,1},{1,1,1},{1,0,1},{0,0,0},{0,1,0},{1,1,0},{1,0,0}
};

float angleX = 0.0, angleY = 0.0, angleZ = 0.0;
float scale = 1.0;
float translateX = 0.0, translateY = 0.0, translateZ = 0.0;

void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawpoly(int a, int b, int c, int d) {
    glBegin(GL_POLYGON);
    glColor3fv(C[a]);
    glVertex3fv(V[a]);
    glColor3fv(C[b]);
    glVertex3fv(V[b]);
    glColor3fv(C[c]);
    glVertex3fv(V[c]);
    glColor3fv(C[d]);
    glVertex3fv(V[d]);
    glEnd();
}

void colorcube() {
    drawpoly(0,1,2,3);
    drawpoly(0,1,5,4);
    drawpoly(1,5,6,2);
    drawpoly(4,5,6,7);
    drawpoly(3,2,6,7);
    drawpoly(0,4,7,3);
}

void display() {
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glTranslatef(translateX, translateY, translateZ);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
    glScalef(scale, scale, scale);
    colorcube();
    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'x':
            angleX += 5.0;
            break;
        case 'X':
            angleX -= 5.0;
            break;
        case 'y':
            angleY += 5.0;
            break;
        case 'Y':
            angleY -= 5.0;
            break;
        case 'z':
            angleZ += 5.0;
            break;
        case 'Z':
            angleZ -= 5.0;
            break;
        case 's':
            scale += 0.1;
            break;
        case 'S':
            scale -= 0.1;
            break;
        case 't':
            translateX += 0.1;
            break;
        case 'T':
            translateX -= 0.1;
            break;
        case 'u':
            translateY += 0.1;
            break;
        case 'U':
            translateY -= 0.1;
            break;
        case 'v':
            translateZ += 0.1;
            break;
        case 'V':
            translateZ -= 0.1;
            break;
        case 27:
            exit(0);
            break; 
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("3D Transformations");
    myinit();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
