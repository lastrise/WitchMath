//
// Created by cloud on 24.10.2020.
//

#include "Visual.h"

RigidBody rb = RigidBody();

void Idle() {
    glutPostRedisplay();
}

void DrawBlock(double a, double b, double c) {
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(a, b, c);
    glVertex3f(-a, b, c);
    glVertex3f(-a, -b, c);
    glVertex3f(a, -b, c);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex3f(a, b, -c);
    glVertex3f(a, -b, -c);
    glVertex3f(-a, -b, -c);
    glVertex3f(-a, b, -c);
    glEnd();
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(-a, b, c);
    glVertex3f(-a, b, -c);
    glVertex3f(-a, -b, -c);
    glVertex3f(-a, -b, c);
    glEnd();
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(a, b, c);
    glVertex3f(a, -b, c);
    glVertex3f(a, -b, -c);
    glVertex3f(a, b, -c);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(-a, b, -c);
    glVertex3f(-a, b, c);
    glVertex3f(a, b, c);
    glVertex3f(a, b, -c);
    glEnd();
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex3f(-a, -b, -c);
    glVertex3f(a , -b, -c);
    glVertex3f(a, -b, c);
    glVertex3f(-a, -b, c);
    glEnd();
}

void Display() {
    glViewport(0, 0, 650, 650);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    solve(rb, 0.0000001);
    glPushMatrix();
    glTranslated(rb.r.x, rb.r.y, rb.r.z - 150);
    glRotated(360 * acos(rb.q.r) / M_PI, rb.q.i, rb.q.j, rb.q.k);
    DrawBlock(HEIGHT, WIDTH, DEPTH);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void initVisual(int argc, char * argv []) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(300,300);
    glutCreateWindow("WITCH MATH");
    glutDisplayFunc(Display);
    glutIdleFunc(Idle);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}