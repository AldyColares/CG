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
    void resizeGL(int w, int h);
    void setWidth(int w);
    void setHeight(int h);


private:
    void setOrthoSize(int size);
    void setAngleX(int alpha);
    void setAngleY(int alpha);
    float
        orthoSize,
        width,
        height,
        angleX,
        angleY,
        angleZ,
        zoom;
        CubeScenerio cubeScenerio;

    QPoint position;



   float Red, Green, Blue;

};




#endif // GLWIDGET_H
