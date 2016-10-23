#ifndef CUBESCENERIO_H
#define CUBESCENERIO_H
#include <GL/glu.h>


class CubeScenerio
{
public:
    CubeScenerio();
    void draw();


private:

    GLfloat const red[3] = {0.8,0,0};
    GLfloat const green[3] = {0,0.8,0};
    GLfloat const blue[3] = {0,0,0.8};

};


#endif // CUBESCENERIO_H
