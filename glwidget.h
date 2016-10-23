#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "cubeScenario.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resize(int w, int h);


private:
    void setOrthoSize(int size);
    float
        orthoSize,
        width,
        height,
        angleX,
        angleY,
        zoom;
        CubeScenerio cubeScenerio;

    QPoint position;



   float Red, Green, Blue;

};




#endif // GLWIDGET_H
