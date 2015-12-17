 #include "ipoint.h"

IPoint::IPoint(QVector3D point, QVector3D normal)
{
    this->point = point;
    this->normal = normal;
}

IPoint::IPoint()
{

}

void IPoint::set_normal(QVector3D normal){
    this->normal = normal;
    normal.normalize();
}

void IPoint::set_point(QVector3D point){
    this->point = point;
}

void IPoint::set_object(Shapes * object){
    this->object = object;

}

