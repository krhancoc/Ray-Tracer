#ifndef MATERIAL_H
#define MATERIAL_H

#include <QVector3D>

class Material
{
public:
    Material();
    Material(const Material &mat);
    Material(QVector3D amb, QVector3D spec, QVector3D diffuse, QVector3D reflec,float p);
    QVector3D ambient;
    QVector3D specular;
    QVector3D diffuse;
    QVector3D reflective;
    float p;
};

#endif // MATERIAL_H
