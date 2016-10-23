#include "PineTree.h"
#include <GL/glu.h>


using namespace std;

PineTree::PineTree()
{
    setCenter(0,5,0);
    setColor(0.3,0.3,0);
    setSize(1);
    n = 50;
}

void PineTree::draw(){

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

    glBegin(GL_TRIANGLE_FAN);

    glEnd();


}


