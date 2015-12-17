#ifndef SHAPES_H
#define SHAPES_H

#include <ray.h>
#include <ipoint.h>
#include <material.h>
class IPoint;

class Shapes
{
public:
    Material material;
    virtual ~Shapes() {}
    virtual bool intersect(Ray &ray,float &t, IPoint &ipoint) =0;
    virtual bool intersect(Ray &ray) =0;
    void setMaterial(Material mat);
    virtual void reverseNormal() =0;


};


class Sphere : public Shapes
{
public:
    Sphere(QVector3D center, float radius);
    QVector3D center;
    float radius;
    //Intersect with object return t values
    virtual bool intersect(Ray &ray,float &t, IPoint &ipoint);

    //Basic implementation check if object is intersected
    virtual bool intersect(Ray &ray);
    virtual void reverseNormal();
};


class Cube : public Shapes
{
public:
    Cube(QVector3D FTRCorner,float height,float width,float depth);
    QVector3D FTRCorner;
    float height;
    float width;
    virtual bool intersect(Ray &ray,float &t, IPoint &ipoint);
    virtual bool intersect(Ray &ray);
    virtual void reverseNormal();

};

class Plane: public Shapes
{
public:
    Plane(QVector3D top,QVector3D left,QVector3D right);
    Plane();
    QVector3D top;
    QVector3D left;
    QVector3D right;
    QVector3D normal;
    float area;
    virtual bool intersect(Ray &ray,float &t, IPoint &ipoint);
    virtual bool intersect(Ray &ray);
    virtual void reverseNormal();


};

class Square : public Shapes
{
public:
    Square(QVector3D a, QVector3D b,QVector3D c,QVector3D d,Material &m);

    Plane * tris[2];
    QVector3D topLeft;
    float height;
    float width;

    virtual bool intersect(Ray &ray,float &t, IPoint &ipoint);
    virtual bool intersect(Ray &ray);
    virtual void reverseNormal();

};

class Pyramid: public Shapes
{
public:
    Pyramid(QVector3D a, QVector3D b, QVector3D c, QVector3D d, Material &m);
    Plane * tris[4];
    virtual bool intersect(Ray &ray,float &t, IPoint &ipoint);
    virtual bool intersect(Ray &ray);
    virtual void reverseNormal();
};

#endif // SHAPES_H
