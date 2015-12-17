#ifndef RAY_H
#define RAY_H

#include <QVector3D>

class Ray
{
public:

    QVector3D vect;
    QVector3D point;

    Ray(QVector3D vect,QVector3D point);

private:

};

#endif // RAY_H
