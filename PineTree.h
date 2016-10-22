#ifndef TREE_H
#define TREE_H
#include "axis.h"

class PineTree
{
public:
    PineTree();
    void setCenter(vertex);
    void setCenter(float, float, float);
    void setColor(float, float, float);
    void setSize(float);
    void draw();
    void wireframe();
    vertex* normal(vertex a,vertex b,vertex c);

private:
    int n;
    vertex center;
    float
        size,
        color[3];
};

void PineTree::setCenter(vertex v)
{
    center.x = v.x;
    center.y = v.y;
    center.z = v.z;
}

void PineTree::setCenter(float X, float Y, float Z)
{
    center.x = X;
    center.y = Y;
    center.z = Z;
}

void PineTree::setColor(float R, float G, float B)
{
    color[0] = R;
    color[1] = G;
    color[2] = B;
}

void PineTree::setSize(float s)
{
    size = s;
}

#endif // TREE_H
