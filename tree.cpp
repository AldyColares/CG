#include "tree.h"
#include <GL/glu.h>
#include <cmath>
#define TAU 2*M_PI

using namespace std;

Tree::Tree()
{
    setCenter(0,5,0);
    setColor(0.3,0.3,0);
    setSize(1);
    n = 50;
}

void Tree::draw(){

    GLfloat mat_ambient[]   = {0.0, 0.0, 0.0, 0.0};
    GLfloat mat_diffuse[]   = {0.0, 0.0, 0.0, 0.0};
    GLfloat mat_specular[]  = {0.0, 0.0, 0.0, 0.0};
    //o valor expoente m da especular.
    GLfloat mat_shininess[] = {0};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHTING);
    glColor3fv(color);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < n; i++)
    {

    }
    glEnd();
}
