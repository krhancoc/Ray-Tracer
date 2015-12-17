#include "material.h"

Material::Material()
{
    p =20;
    ambient =QVector3D(.5,.5,.5);
    diffuse =QVector3D(0,0,0);
    specular = QVector3D(0,0,0);
    reflective = QVector3D(1,1,1);
}

Material::Material(QVector3D amb, QVector3D spec, QVector3D diffuse, QVector3D reflec, float p)
{
    ambient = QVector3D(amb);
    specular = QVector3D(spec);
    this->diffuse = QVector3D(diffuse);
    reflective = QVector3D(reflec);
    this->p = p;
}

Material::Material(const Material &mat)
{
    this->ambient = QVector3D(mat.ambient);
    this->diffuse = QVector3D(mat.diffuse);
    this->reflective = QVector3D(mat.reflective);
    this->specular = QVector3D(mat.specular);
    this->p = mat.p;
}
