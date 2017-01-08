#include "glwidget.h"
#include <exception>
#include <iostream>
#include <QKeyEvent>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    unitmove = 0.5;
    zoom = 1;

    setFocus();
}

void GLWidget::initializeGL()
{
    GLfloat intensity = 1;

    GLfloat light_spec[] = {intensity, intensity, intensity, 1.0f};
    GLfloat light_dif[] = {intensity, intensity, intensity, 1.0f};
    GLfloat light_amb[] = {intensity/4, intensity/4, intensity/4, 1.0f};
    GLfloat light_position[] = { 0.0, 50.0, 0.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_spec);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glShadeModel (GL_SMOOTH);

    glClearColor(0.1f,0.1f,0.1f,1.0f);

    //glEnable(GL_CULL_FACE);

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


    glMatrixMode(GL_MODELVIEW);

    angleX = 0;
    angleY = 0;
    angleZ = 0;
    glLoadIdentity();


    //glPushMatrix();

    glTranslatef(0.0, -8.0, 0.0);
    //glRotatef(angleX , 1.0, 0.0, 0.0);
    //glRotatef(angleY , 0.0, 1.0, 0.0);
    //glRotatef(angleZ , 0.0, 0.0, 1.0);
    gluLookAt(  0 + (left - right),         0,         -9 + (forward - backward),  //eye
                0 + ( leftcam - rightcam) + (left - right), (upcam - downcam),  9 + (forward - backward),  //center
                0,           100,                   0 );//up
    glColor3f(1,0,0);
    //glScalef(5,5,5);
    //cubeScenerio.draw();
    opGLScenerio->draw(0);
   // glTranslatef(0.0, 0.0, 0.0);

    //glPopMatrix();

    //          x                           y                    z


}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0,0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45.0, (float)width/height, 0.01, 200.0 );
    updateGL();

    //setWidth(w);
    //setHeight(h);

}

void GLWidget::keyPressEvent(QKeyEvent *event){

    switch (event->key())
    {
    case Qt::Key::Key_W:
        forward += unitmove;
        updateGL();
        break;

    case Qt::Key::Key_S:
        backward += unitmove;
        updateGL();
        break;

    case Qt::Key::Key_D:
        right += unitmove;
        updateGL();
        break;

    case Qt::Key::Key_A:
        left += unitmove;
        updateGL();
        break;
    case Qt::Key::Key_U:
        upcam += unitmove;
        updateGL();
        break;

    case Qt::Key::Key_J:
        downcam += unitmove;
        updateGL();

        break;
    case Qt::Key::Key_H:
        leftcam += unitmove;
        updateGL();
        break;
    case Qt::Key::Key_K:
        rightcam += unitmove;
        updateGL();
        break;
    default:
        break;
    }

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
