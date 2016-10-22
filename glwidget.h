#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resize(int w, int h);

private:
    float
        orthoSize,
        width,
        height,
        angleX,
        angleY,
        zoom;

    QPoint position;

    Axis axis;
    Block orthoBox;
    ChessTable table;
    Piece piece;

   float Red, Green, Blue;

};

};



#endif // GLWIDGET_H
