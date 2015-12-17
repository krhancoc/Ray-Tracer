#ifndef TRACER_H
#define TRACER_H
#include<QColor>
#include <ray.h>
#include <ipoint.h>
#include <scene.h>

class Tracer
{
public:
    Tracer(Scene scene);
    QVector3D trace(Ray &ray,int depth);
    Scene scene;
};

#endif // TRACER_H
