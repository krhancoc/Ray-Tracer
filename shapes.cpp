#include "shapes.h"
#include <cmath>
#include <iostream>
#include <polyroots.h>
#include <cmath>
#include <QMatrix4x4>
#define DISTANCE 0.01

void Shapes::setMaterial(Material mat)
{
    material = Material(mat);
}

Sphere::Sphere(QVector3D center, float radius)
{
    this->center = center;
    this->radius = radius;
}

bool Sphere::intersect(Ray &ray, float &t, IPoint &ipoint)
{
    float t_min = INFINITY;
    QVector3D oc = ray.point - center;
    double b = 2 * (QVector3D::dotProduct(ray.vect,oc));

    double c = oc.lengthSquared() - std::pow(radius,2);

    double roots[2];

    int num = quadraticRoots((double)1,b,c,roots);
    bool check_roots = false;
    for(int i = 0; i < num ; i++)
    {
        if(roots[i] > 0 && roots[i] < t_min)
        {
            check_roots = true;
            t_min = roots[i];
        }
    }
    if(check_roots){
        t = t_min;
        QVector3D newPoint = QVector3D(
                    ray.point[0] + (t*ray.vect[0]),
                    ray.point[1] + (t*ray.vect[1]),
                    ray.point[2] + (t*ray.vect[2])
                    );
        ipoint.set_point(newPoint);
        ipoint.set_normal(QVector3D(ipoint.point - center));
        float x = ipoint.point[0] + (DISTANCE*ipoint.normal[0]);
        float y = ipoint.point[1] + (DISTANCE*ipoint.normal[1]);
        float z = ipoint.point[2] + (DISTANCE*ipoint.normal[2]);
        ipoint.point[0] = x;
        ipoint.point[1] = y;
        ipoint.point[2] = z;
        ipoint.set_object(this);
    }

    return check_roots;
}

bool Sphere::intersect(Ray &ray)
{
   QVector3D oc = ray.point - center;
   double b = 2 * (QVector3D::dotProduct(ray.vect,oc));

   double c = oc.lengthSquared() - std::pow(radius,2);

   double roots[2];

   int num = quadraticRoots((double)1,b,c,roots);
   bool check_roots = false;
   for(int i = 0; i < num ; i++)
   {
       if(roots[i] > 0)
       {
           check_roots = true;
       }
   }
   return check_roots;

}

Plane::Plane(QVector3D top,QVector3D left,QVector3D right)
{
    this->top = top;
    this->left = left;
    this->right = right;
    normal = QVector3D(QVector3D::crossProduct(
                           left-top,
                           right-top
                           ));
    normal.normalize();
    float length_a = (left-top).length();
    float length_b = (right-top).length();
    area = (length_a * length_b) / 2;

}

bool Plane::intersect(Ray &ray, float &t, IPoint &ipoint)
{
    //A-P
    //find point on plane of triangle
    float temp = (QVector3D::dotProduct(ray.point - right, normal)) / QVector3D::dotProduct((ray.point - (ray.point + ray.vect)),normal);
    if ( temp > 0){
        QVector3D m = QVector3D(
                         ray.vect[0] * temp,
                         ray.vect[1] * temp,
                         ray.vect[2] * temp
                      );
        QVector3D onPlane = ray.point +  m;
        //std::cout <<onPlane.x << "," << onPlane.y<< ","<<onPlane.z;
        float alpha = 0.5 * (QVector3D::dotProduct(QVector3D::crossProduct((right-left),(onPlane-left)),normal))/ area;
        float beta = 0.5 * (QVector3D::dotProduct(QVector3D::crossProduct((top -right),(onPlane - right)), normal))/ area;

            //std::cout << "alpha " << alpha <<" beta " << beta ;
        if (alpha < 0 || beta < 0 || alpha + beta > 1){
            return false;
        } else {
            ipoint.point = onPlane;
            ipoint.normal = normal;

            //std::cout<< normal.x() << " " <<normal.y()<< " " <<normal.z() << "\n";
            ipoint.point = ipoint.point + (normal) * 0.01;
            ipoint.set_object(this);
            t = temp;
            return true;
            }
    }
    return false;

}

bool Plane::intersect(Ray &ray)
{

//A-P
    //find point on plane of triangle
    float temp = (QVector3D::dotProduct(ray.point - top, normal)) / QVector3D::dotProduct((ray.point - (ray.point + ray.vect)),normal);
    if ( temp > 0){
        QVector3D m = QVector3D(
                         ray.vect[0] * temp,
                         ray.vect[1] * temp,
                         ray.vect[2] * temp
                      );
        QVector3D onPlane = ray.point +  m;
        //std::cout <<onPlane.x << "," << onPlane.y<< ","<<onPlane.z;
        float alpha = 0.5 * (QVector3D::dotProduct(QVector3D::crossProduct((left-right),(onPlane-right)),normal))/ area;
        float beta = 0.5 * (QVector3D::dotProduct(QVector3D::crossProduct((top -left),(onPlane - left)), normal))/ area;

        //std::cout << "alpha " << alpha <<" beta " << beta ;
        if (alpha < 0 || beta < 0 || alpha + beta > 1){
            return false;
        } else {
            return true;
        }
    }
    return false;


}

Plane::Plane(){};

void Plane::reverseNormal()
{
    normal = -normal;
}

Cube::Cube(QVector3D FTRCorner,float height,float width,float depth)
{
    this->FTRCorner = FTRCorner;
    this->height = height;
    this->width = width;

}

bool Cube::intersect(Ray &ray, float &t, IPoint &ipoint)
{

}

bool Cube::intersect(Ray &ray)
{

}

/*
 *   a ---- d
 *    -
 *    -           -
 *    -             -
 *    b -----------c
 *
 * */
Square::Square(QVector3D a, QVector3D b, QVector3D c, QVector3D d,Material &m)
{
    tris[0] = new Plane(b,c,a);
    tris[0]->setMaterial(Material(m));
    tris[1] =new Plane(d,a,c);
    tris[1]->setMaterial(Material(m));

}

bool Square::intersect(Ray &ray, float &t, IPoint &ipoint)
{
    float t_min = INFINITY;
    bool check_both = false;
    for(int i = 0; i < 2; i++)
    {
        float t_check;
        if(tris[i]->intersect(ray,t_check,ipoint)) {
            if(t_check < t_min && t_check > 0){
                t_min = t_check;
            }
            check_both = true;
        }
    }
    t = t_min;
    return check_both;
}

bool Square::intersect(Ray &ray)
{
    bool check_both = false;
    for(int i = 0; i < 2; i++)
    {
        if(tris[i]->intersect(ray)) {
            check_both = true;
        }
    }
    return check_both;
}

void Square::reverseNormal()
{
    for(int i = 0;i < 2; i++){
        tris[i]->reverseNormal();
    }
}

void Cube::reverseNormal(){};

void Sphere::reverseNormal(){};

Pyramid::Pyramid(QVector3D a, QVector3D b, QVector3D c, QVector3D d, Material &m)
{
    tris[0] = new Plane(a,b,c);
    tris[0]->setMaterial(Material(m));
    tris[1] =new Plane(a,c,d);
    tris[1]->setMaterial(Material(m));
    tris[2] = new Plane(a,d,b);
    tris[2]->setMaterial(Material(m));
    tris[3] = new Plane(c,d,b);
    tris[3]->setMaterial(Material(m));
}

bool Pyramid::intersect(Ray &ray)
{
    bool check_both = false;
    for(int i = 0; i < 2; i++)
    {
        if(tris[i]->intersect(ray)) {
            check_both = true;
        }
    }
    return check_both;
}

bool Pyramid::intersect(Ray &ray, float &t, IPoint &ipoint)
{
    float t_min = INFINITY;
    bool check_both = false;
    for(int i = 0; i < 4; i++)
    {
        float t_check;
        if(tris[i]->intersect(ray,t_check,ipoint)) {
            if(t_check < t_min && t_check > 0){
                t_min = t_check;
            }
            check_both = true;
        }
    }
    t = t_min;
    return check_both;
}

void Pyramid::reverseNormal()
{

}



