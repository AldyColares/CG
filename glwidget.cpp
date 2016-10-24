#include "glwidget.h"
#include <exception>


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{

    zoom = 1;
    setOrthoSize((int)10);

}

void GLWidget::initializeGL()
{
    GLfloat intensity = 0.5;


    GLfloat light_spec[] = {intensity, intensity, intensity, 1.0f};
    GLfloat light_dif[] = {intensity, intensity, intensity, 1.0f};
    GLfloat light_amb[] = {intensity/4, intensity/4, intensity/4, 1.0f};
    GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glShadeModel (GL_SMOOTH);

    glClearColor(0.1f,0.1f,0.1f,1.0f);

    glEnable(GL_CULL_FACE);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    // O método para escolher o tipo de shade que vai ser usado.
    //https://www.opengl.org/sdk/docs/man2/xhtml/glShadeModel.xml

}


// http://www.trentreed.net/blog/qt5-opengl-part-3b-camera-control/
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // valores em graus
    angleX = -45;
    angleY = 45;
    angleZ = 0;

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(angleX , 1.0, 0.0, 0.0);
    glRotatef(angleY , 0.0, 1.0, 0.0);
    glRotatef(angleZ , 0.0, 0.0, 1.0);
    cubeScenerio.draw();



}

void GLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-8, +8, -8, +8, 1.0, 80.0);
    glMatrixMode(GL_MODELVIEW);


    //setWidth(w);
    //setHeight(h);

}

void GLWidget::setWidth(int w)
{
    if (w > 0){
        width = w;
    }else{
         throw "Tamanho da largura da tela é menor ou igual a zero: GLWidget::GLWidget";
    }
}

void GLWidget::setHeight(int h)
{
    if (h > 0){
        height = h;
    }else{
        throw "Tamanho da altura da é menor ou igual a zero: GLWidget::GLWidget";
    }
}

void GLWidget::setAngleX(int alpha)
{
    angleX = alpha;
    updateGL();
}

void GLWidget::setAngleY(int alpha)
{
    angleY = alpha;
    updateGL();
}



void GLWidget::setOrthoSize(int size){

    if(size > 0){
        orthoSize = size;
    }else{
        throw "Tamanho da projeção é menor ou igual a zero: GLWidget::GLWidget";
    }

}
