#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void myinit() {
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
    glFlush();
}

void display() {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    float fpx = 20, fpy = 40;
    float theta = 30;  // Angle in degrees
    float PI[9][2] = { {10,10},{10,30},{25,40},{40,30},{40,10},{20,10},{20,20},{30,20},{30,10} };
    float RP[9][2];
    glColor3f(1, 0, 0);
    draw_h(PI);


    for (int i = 0; i < 9; i++) {
        RP[i][0] = cos(theta) * (PI[i][0] - fpx) - sin(theta) * (PI[i][1] - fpy) + fpx;
        RP[i][1] = sin(theta) * (PI[i][0] - fpx) + cos(theta) * (PI[i][1] - fpy) + fpy;
    }

    glColor3f(1, 1, 0);
    draw_h(RP);
}

int main(int argc, char** argv) {
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
