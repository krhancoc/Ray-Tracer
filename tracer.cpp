#include "tracer.h"
#include <cmath>
Tracer::Tracer(Scene scene)
{
    this->scene = scene;
}

QVector3D Tracer::trace(Ray &ray, int depth)
{
    if (depth == 0 ) {
        return QVector3D(0,0,0);
    } else {
        float t_min = INFINITY;
        float t;
        IPoint final;
        for(int i = 0; i < scene.objects.size(); i ++){
            Shapes * object = scene.objects[i];
            IPoint p;
            if(object->intersect(ray,t,p)){
               if( t < t_min){
                   t_min = t;
                   final = p;
               }
            }
        }
        float final_r = 0;
        float final_g = 0;
        float final_b = 0;
        QVector3D r;
        if(t_min < INFINITY)
        {

           float red = final.object->material.ambient[0] * scene.ambient[0];
           float green  = final.object->material.ambient[1] * scene.ambient[1];
           float blue  = final.object->material.ambient[2] * scene.ambient[2];
           QVector3D ambience = QVector3D(red,green,blue);
           QVector3D diffuse =  QVector3D(0,0,0);
           QVector3D spec = QVector3D(0,0,0);

           for(int q =0; q < scene.lights.size(); q ++){

               //Find Diffuse and Specular
               Lights * light = scene.lights[q];
               QVector3D toLightRay = light->position - final.point;
               toLightRay.normalize();
               Ray lightRay = Ray(toLightRay,final.point);
               bool shadow = false;

               for(int h = 0;h < scene.objects.size() ; h ++){
                   if(scene.objects[h]->intersect(lightRay)){
                        shadow = true;
                   }
               }
               if(!shadow){
                   //Diffuse
                   float l_n = std::max((float)0,QVector3D::dotProduct(toLightRay,final.normal));
                   float obj_red = final.object->material.diffuse[0];
                   float obj_green = final.object->material.diffuse[1];
                   float obj_blue =final.object->material.diffuse[2];
                   float light_red = light->color[0];
                   float light_green =light->color[1];
                   float light_blue= light->color[2];
                   float final_red = obj_red * l_n * light_red;
                   float final_green = obj_green * l_n * light_green;
                   float final_blue = obj_blue * l_n * light_blue;
                   diffuse[0] += final_red;
                   diffuse[1] += final_green;
                   diffuse[2] += final_blue;

                   //Specular
                   //relfection r = -l + 2(n dot l)n
                   QVector3D l = QVector3D(toLightRay);
                   l.normalize();
                   QVector3D n = QVector3D(final.normal);
                   n.normalize();
                   r = QVector3D(2*QVector3D::dotProduct(n,l)*n - l);
                   r.normalize();
                   if(QVector3D::dotProduct(n,l) >= 0) {
                       // vector v
                       QVector3D v= QVector3D(-(ray.vect));
                       v.normalize();

                       // max(v dot r,0)
                       float spec_mid = std::max((float)0,QVector3D::dotProduct(v,r));
                       float shine = std::pow(spec_mid,final.object->material.p);
                      // std::cout << shine << std::endl;

                       final_red = final.object->material.specular[0] * shine * light->color[0];
                       final_green = final.object->material.specular[1] * shine * light->color[1];
                       final_blue = final.object->material.specular[2] * shine * light->color[2];

                       spec[0] += final_red;
                       spec[1] += final_green;
                       spec[2] += final_blue;
                   } else {
                       spec[0] += 0;
                       spec[1] += 0;
                       spec[2] += 0;
                   }
              }


           }
           //Reflection
           QVector3D reflection;
           QVector3D check = final.object->material.reflective;
           if(check[0] == 0 && check[1] == 0 && check[2] == 0) {
               reflection = QVector3D(0,0,0);
           } else {
               Ray reflect_ray = Ray(r,final.point);
               reflection = this->trace(reflect_ray, depth -1);
               reflection[0] = reflection[0] * final.object->material.reflective[0];
               reflection[1] = reflection[1] * final.object->material.reflective[1];
               reflection[2] = reflection[2] * final.object->material.reflective[2];
           }
           final_r = ambience[0] + diffuse[0] + spec[0] + reflection[0] > 1 ? 1: ambience[0] + diffuse[0] + spec[0] + reflection[0] ;
           final_g = ambience[1] + diffuse[1] + spec[1] + reflection[1] > 1 ? 1: ambience[1] + diffuse[1] + spec[1] + reflection[1] ;
           final_b = ambience[2] + diffuse[2] + spec[2] + reflection[2] > 1 ? 1: ambience[2] + diffuse[2] + spec[2] + reflection[2] ;
        } else
        {
            final_r = .7;
            final_g = .7;
            final_b = 1;

        }

           return QVector3D(final_r,final_g,final_b);
   }

}

