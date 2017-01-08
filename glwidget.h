#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include "cubeScenario.h"
#include "opglscenerio.h"


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
    void keyPressEvent(QKeyEvent* event);
    float
        dez,
        forward,
        backward,
        unitmove,
        right,
        left,
        upcam,
        downcam,
        leftcam,
        rightcam,
        width,
        height,
        angleX,
        angleY,
        angleZ,
        zoom;
        OpGLScenerio* opGLScenerio = new OpGLScenerio();

        CubeScenerio cubeScenerio;

    QPoint position;



   float Red, Green, Blue;

};




#endif // GLWIDGET_H
