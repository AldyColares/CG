#include "opglscenerio.h"


OpGLScenerio::OpGLScenerio()
{
    vectorScenarioObject = loadMaterial->loadObject();
}

void OpGLScenerio::draw(int orderMaterial)
{
    scenarioObject = vectorScenarioObject->at(orderMaterial);
    proMat = scenarioObject->getPropertyMaterial();
    sizeFace = scenarioObject->getSizeFaces();
    GLfloat mat_ambient[]   = {proMat.materialAmbientRed, proMat.materialAmbientGreen, proMat.materialAmbientBlue, 1};
    GLfloat mat_diffuse[]   = {proMat.materialDiffuseRed, proMat.materialDiffuseGreen, proMat.materialDiffuseBlue, 1};
    GLfloat mat_specular[]  = {proMat.materialSpecularRed, proMat.materialSpecularGreen, proMat.materialSpecularBlue, 1};
    GLfloat mat_shininess[] = {proMat.materialShininess};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHTING);

    for (int i = 0; i < sizeFace; ++i) {
        NTHface = scenarioObject->getFaceObjIn3D(i);

        glColor3f(NTHface.red, NTHface.green, NTHface.blue);

        glNormal3f(NTHface.normal.x,NTHface.normal.y,NTHface.normal.z);

        glBegin(GL_TRIANGLES);

        auxPoint = scenarioObject->getVectorObjIn3D(NTHface.idV1);
        glVertex3f(auxPoint.x, auxPoint.y, auxPoint.z);

        auxPoint = scenarioObject->getVectorObjIn3D(NTHface.idV2);
        glVertex3f(auxPoint.x, auxPoint.y, auxPoint.z);

        auxPoint = scenarioObject->getVectorObjIn3D(NTHface.idV3);
        glVertex3f(auxPoint.x, auxPoint.y, auxPoint.z);

        glEnd();
    }

}
