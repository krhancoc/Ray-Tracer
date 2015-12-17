#include "ray.h"

Ray::Ray(QVector3D vect, QVector3D point)
{
    this->vect = vect;
    this->vect.normalize();
    this->point = point;
}

