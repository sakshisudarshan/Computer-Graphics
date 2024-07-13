#include<stdio.h>
#include <GL/glut.h>

float V[8][3] = {
   {-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1}
};

float C[8][3] = {
  {0,0,1},{0,1,1},{1,1,1},{1,0,1},{0,0,0},{0,1,0},{1,1,0},{1,0,0}
};

float theta[3]={0,0,0};
int flag=2;

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
    glRotatef(theta[0],1,0,0);
    glRotatef(theta[1],0,1,0);
    glRotatef(theta[2],0,0,1);
    colorcube();
    glFlush();
    glutSwapBuffers();
}

void idleFunc(){
    theta[flag]++;
    if(theta[flag]>360)
       theta[flag]=0;
    glutPostRedisplay();
}
void m(int b,int s, int x, int y)
{
    if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN)
        flag=2;
    if(b==GLUT_MIDDLE_BUTTON && s==GLUT_DOWN)
        flag=1;
    if(b==GLUT_RIGHT_BUTTON && s==GLUT_DOWN)
        flag=0;

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Cube Rotate");
    myinit();
    glutDisplayFunc(display);
    glutMouseFunc(m);
    glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}
