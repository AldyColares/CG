#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{

}

void GLWidget::initializeGL()
{


    GLfloat light_spec[] = {intensity, intensity, intensity, 1.0f};
    GLfloat light_dif[] = {intensity, intensity, intensity, 1.0f};
    GLfloat light_amb[] = {intensity/4, intensity/4, intensity/4, 1.0f};
    GLfloat light_position[] = { distance, distance, distance, 1 };

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glClearColor(1.0f,1.0f,0.0f,1.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    // O método para escolher o tipo de shade que vai ser usado.
    //https://www.opengl.org/sdk/docs/man2/xhtml/glShadeModel.xml
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-0, 0,  // left, right
            -0, 0,  // bottom, up
            -0, 0); // near, far

    glMatrixMode(GL_MODELVIEW);

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


}

void GLWidget::resize(int w, int h)
{

}
