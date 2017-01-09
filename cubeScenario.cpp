#include "cubeScenario.h"
//#include <GL/glu.h>

//abaixo é um construtor.
CubeScenerio::CubeScenerio()
{
    sizecube = 2.0;

}

void CubeScenerio::draw(){
    //cubo de ouro.
    GLfloat mat_ambient[]   = {0.747250, 0.799500, 0.774500, 1};
    GLfloat mat_diffuse[]   = {0.751640, 0.606480, 0.226480, 1};
    GLfloat mat_specular[]  = {0.628281, 0.555802, 0.366065, 1};
    GLfloat mat_shininess[] = {51.2};


    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHTING);

    glColor3f(0.0, 0.8 ,0.0);

    glBegin(GL_QUADS);			// Face posterior
        glNormal3f(0.0, 0.0, 1.0);	// Normal da face
        glVertex3f(sizecube, sizecube, sizecube);
        glVertex3f(-sizecube, sizecube, sizecube);
        glVertex3f(-sizecube, -sizecube, sizecube);
        glVertex3f(sizecube, -sizecube, sizecube);
    glEnd();

    glColor3f(0, 0.9 ,0.9);
    glBegin(GL_QUADS);			// Face frontal
        glNormal3f(0.0, 0.0, -1.0); 	// Normal da face
        glVertex3f(sizecube, sizecube, -sizecube);
        glVertex3f(sizecube, -sizecube, -sizecube);
        glVertex3f(-sizecube, -sizecube, -sizecube);
        glVertex3f(-sizecube, sizecube, -sizecube);
    glEnd();

    glColor3f(0.8, 0.8 ,0);

    glBegin(GL_QUADS);			// Face lateral esquerda
        glNormal3f(-1.0, 0.0, 0.0); 	// Normal da face
        glVertex3f(-sizecube, sizecube, sizecube);
        glVertex3f(-sizecube, sizecube, -sizecube);
        glVertex3f(-sizecube, -sizecube, -sizecube);
        glVertex3f(-sizecube, -sizecube, sizecube);
    glEnd();

    glColor3f(0.9, 0.9 ,0.0);
    glBegin(GL_QUADS);			// Face lateral direita
        glNormal3f(1.0, 0.0, 0.0);	// Normal da face
        glVertex3f(sizecube, sizecube, sizecube);
        glVertex3f(sizecube, -sizecube, sizecube);
        glVertex3f(sizecube, -sizecube, -sizecube);
        glVertex3f(sizecube, sizecube, -sizecube);
    glEnd();
    
    glColor3f(0.6, 0.9 ,0.4);
    glBegin(GL_QUADS);			// Face superior
        glNormal3f(0.0, 1.0, 0.0);  	// Normal da face
        glVertex3f(-sizecube, sizecube, -sizecube);
        glVertex3f(-sizecube, sizecube, sizecube);
        glVertex3f(sizecube, sizecube, sizecube);
        glVertex3f(sizecube, sizecube, -sizecube);
    glEnd();
    
    glColor3f(0.43, 0.87 ,0.23);
    glBegin(GL_QUADS);			// Face inferior
        glNormal3f(0.0, -1.0, 0.0); 	// Normal da face
        glVertex3f(-sizecube, -sizecube, -sizecube);
        glVertex3f(sizecube, -sizecube, -sizecube);
        glVertex3f(sizecube, -sizecube, sizecube);
        glVertex3f(-sizecube, -sizecube, sizecube);
    glEnd();
}
