#include "cubeScenario.h"
#include <GL/glu.h>

//abaixo é um construtor.
CubeScenerio::CubeScenerio()
{


}

void CubeScenerio::draw(){

    GLfloat mat_ambient[]   = {0.247250, 0.199500, 0.074500, 1};
    GLfloat mat_diffuse[]   = {0.751640, 0.606480, 0.226480, 1};
    GLfloat mat_specular[]  = {0.628281, 0.555802, 0.366065, 1};
    GLfloat mat_shininess[] = {51.2};

    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHTING);

    glColor3f(0, 0.8 ,0);

    glBegin(GL_QUADS);			// Face posterior
        glNormal3f(0.0, 0.0, -1.0);	// Normal da face
        glVertex3f(40.0, 40.0, 40.0);
        glVertex3f(-40.0, 40.0, 40.0);
        glVertex3f(-40.0, -40.0, 40.0);
        glVertex3f(40.0, -40.0, 40.0);
    glEnd();


    glBegin(GL_QUADS);			// Face frontal
        glNormal3f(0.0, 0.0, 1.0); 	// Normal da face
        glVertex3f(40.0, 40.0, -40.0);
        glVertex3f(40.0, -40.0, -40.0);
        glVertex3f(-40.0, -40.0, -40.0);
        glVertex3f(-40.0, 40.0, -40.0);
    glEnd();
    
    glBegin(GL_QUADS);			// Face lateral esquerda
        glNormal3f(1.0, 0.0, 0.0); 	// Normal da face
        glVertex3f(-40.0, 40.0, 40.0);
        glVertex3f(-40.0, 40.0, -40.0);
        glVertex3f(-40.0, -40.0, -40.0);
        glVertex3f(-40.0, -40.0, 40.0);
    glEnd();
    
    glBegin(GL_QUADS);			// Face lateral direita
        glNormal3f(-1.0, 0.0, 0.0);	// Normal da face
        glVertex3f(40.0, 40.0, 40.0);
        glVertex3f(40.0, -40.0, 40.0);
        glVertex3f(40.0, -40.0, -40.0);
        glVertex3f(40.0, 40.0, -40.0);
    glEnd();
    
    glBegin(GL_QUADS);			// Face superior
        glNormal3f(0.0, -1.0, 0.0);  	// Normal da face
        glVertex3f(-40.0, 40.0, -40.0);
        glVertex3f(-40.0, 40.0, 40.0);
        glVertex3f(40.0, 40.0, 40.0);
        glVertex3f(40.0, 40.0, -40.0);
    glEnd();
    
    glBegin(GL_QUADS);			// Face inferior
        glNormal3f(0.0, 1.0, 0.0); 	// Normal da face
        glVertex3f(-40.0, -40.0, -40.0);
        glVertex3f(40.0, -40.0, -40.0);
        glVertex3f(40.0, -40.0, 40.0);
        glVertex3f(-40.0, -40.0, 40.0);
}
