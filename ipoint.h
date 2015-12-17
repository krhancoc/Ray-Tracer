#ifndef IPOINT_H
#define IPOINT_H

#include<QVector3D>
#include <shapes.h>
class Shapes;

class IPoint
{
public:
    IPoint();
    IPoint(QVector3D point, QVector3D normal);
    void set_normal(QVector3D normal);
    void set_point(QVector3D point);
    void set_object(Shapes * object);

    //MAKE SURE TO NORMALIZE BITCH
    QVector3D normal;
    QVector3D point;
    Shapes * object;


};

#endif // IPOINT_H
