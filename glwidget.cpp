#include "glwidget.h"
#include <exception>


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    double size = 2;

    Red = 0.5;
    Green = 0.5;
    Blue = 0.5;

    zoom = 1;
    setOrthoSize((int)1);



}

void GLWidget::initializeGL()
{
    GLfloat intensity = 1;
    GLfloat distance = orthoSize;


    GLfloat light_spec[] = {intensity, intensity, intensity, 1.0f};
    GLfloat light_dif[] = {intensity, intensity, intensity, 1.0f};
    GLfloat light_amb[] = {intensity/4, intensity/4, intensity/4, 1.0f};
    GLfloat light_position[] = { 0, 20, 10, 1 };

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glShadeModel (GL_SMOOTH);

    glClearColor(0.2f,0.2f,0.2f,1.0f);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    // O método para escolher o tipo de shade que vai ser usado.
    //https://www.opengl.org/sdk/docs/man2/xhtml/glShadeModel.xml

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-orthoSize*zoom   ,orthoSize*zoom,  // left, right
            -orthoSize*zoom   ,orthoSize*zoom,  // bottom, up
            -orthoSize*zoom ,orthoSize*zoom*10); // near, far

    glMatrixMode(GL_MODELVIEW);


}


// http://www.trentreed.net/blog/qt5-opengl-part-3b-camera-control/
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    glLoadIdentity();
    glViewport(0, 0, width, height);
    cubeScenerio.draw();

    glPopMatrix();

    float const aspectRatio = height/width;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //http://stackoverflow.com/questions/2571402/explain-the-usage-of-glortho
    glOrtho(-orthoSize*zoom             ,orthoSize*zoom,  // left, right
            -orthoSize*zoom*aspectRatio ,orthoSize*zoom*aspectRatio,  // bottom, up
            -orthoSize*zoom*5           ,orthoSize*zoom*5); // near, far
    glMatrixMode(GL_MODELVIEW);

}

void GLWidget::resize(int w, int h)
{

}



void GLWidget::setOrthoSize(int size){

    if(size > 0){
        orthoSize = size;
    }else{
        throw "Tamanho da projeção é menor ou igual a zero: GLWidget::GLWidget";
    }

}
