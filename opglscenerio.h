#ifndef OPGLSCENERIO_H
#define OPGLSCENERIO_H
#include "loadmaterial.h"
#include <GL/glu.h>


class OpGLScenerio
{
public:
    OpGLScenerio();
    void draw(int orderMaterial);
    propertyMaterial proMat;

    Point3D auxPoint;
    face3D NTHface;
    int sizeFace;
    LoadMaterial* loadMaterial =  new LoadMaterial();
    vector<ScenarioObject*> *vectorScenarioObject;
    ScenarioObject* scenarioObject;

};

#endif // OPGLSCENERIO_H
