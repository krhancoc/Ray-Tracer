#include "scene.h"

Scene::Scene()
{
     ambient = QVector3D(0.5,0.5,0.5);
     //Center Circle
     Shapes  * center_circle = new Sphere (QVector3D(2,5,3),2.0);
     center_circle->setMaterial(Material(QVector3D(.5,0,0),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(.1,.1,.1),20));
     Shapes  * far_circle = new Sphere (QVector3D(-2,5,3),2.0);
     far_circle->setMaterial(Material(QVector3D(.5,0,0),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(.1,.1,.1),20));

     Shapes  * c1 = new Sphere (QVector3D(0,3,3),2.0);
     c1->setMaterial(Material(QVector3D(.5,0,0),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(.1,.1,.1),20));
     Shapes  * c2 = new Sphere (QVector3D(0,1,3),2.0);
     c2->setMaterial(Material(QVector3D(.5,0,0),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(.1,.1,.1),20));
     Shapes  * c3 = new Sphere (QVector3D(0,-1,3),2.0);
     c3->setMaterial(Material(QVector3D(.5,0,0),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(.1,.1,.1),20));
     Shapes  * c4 = new Sphere (QVector3D(0,2,3),2.0);
     c4->setMaterial(Material(QVector3D(.5,0,0),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(.1,.1,.1),20));
     Shapes  * c5 = new Sphere (QVector3D(0,0,3),2.0);
     c5->setMaterial(Material(QVector3D(.5,0,0),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(.1,.1,.1),20));

     Shapes  * c6 = new Sphere (QVector3D(0,-3.5,3),.25);
     c6->setMaterial(Material(QVector3D(1,1,1),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(0,0,0),1));

     Shapes  * c7 = new Sphere (QVector3D(0,-4,3),.25);
     c7->setMaterial(Material(QVector3D(1,1,1),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(0,0,0),1));

     Shapes  * c8 = new Sphere (QVector3D(-0.78,-4.11,3),.25);
     c8->setMaterial(Material(QVector3D(1,1,1),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(0,0,0),1));

     Shapes  * c9 = new Sphere (QVector3D(0.66,-4.87,3),.25);
     c9->setMaterial(Material(QVector3D(1,1,1),QVector3D(.15,.15,.15),QVector3D(.6,.6,.6),QVector3D(0,0,0),1));

     Material m = Material(QVector3D(.5,0,0),QVector3D(.25,.25,.25),QVector3D(.6,.6,.6),QVector3D(0,0,0),10);
     Shapes * top_plane = new Square(QVector3D(-50,-25,100),QVector3D(50,-25,100),QVector3D(50,-25,-10),QVector3D(-50,-25,-10),m);

     Material t = Material(QVector3D(0,.25,.25),QVector3D(.25,.25,.25),QVector3D(.6,.6,.6),QVector3D(.1,.1,.1),10);
     Shapes * bottom = new Square(QVector3D(-100,25,200),QVector3D(-100,25,-10),QVector3D(100,25,-10),QVector3D(100,25,200),t);

     Material u = Material(QVector3D(0,0,0.5),QVector3D(.25,.25,.25),QVector3D(.6,.6,.6),QVector3D(0,0,0),10);
     Shapes * back_plane = new Square(QVector3D(-50,-25,100),QVector3D(-50,25,100),QVector3D(50,25,100),QVector3D(50,-25,100),u);

     Material i = Material(QVector3D(0,.5,.5),QVector3D(.25,.25,.25),QVector3D(.2,.2,.2),QVector3D(.5,.5,.5),10);
     Shapes * left_plane = new Square(QVector3D(-50,-25,-10),QVector3D(-50,25,-10),QVector3D(-50,25,100),QVector3D(-50,-25,100),i);

     Material o = Material(QVector3D(.5,.5,0),QVector3D(.25,.25,.25),QVector3D(.6,.6,.6),QVector3D(0,0,0),10);
     Shapes * right_plane = new Square(QVector3D(50,-25,100),QVector3D(50,25,100),QVector3D(50,25,-10),QVector3D(50,-25,-10),o);

     Shapes * pyramid = new Pyramid(QVector3D(5,-3,7),QVector3D(3,-1,5),QVector3D(7,-1,5),QVector3D(6,-1,9),t);

     Shapes * triangle = new Plane(QVector3D(0,-5,4),QVector3D(-2,-3,4),QVector3D(2,-3,4));
     triangle->setMaterial(i);
  //   Material p = Material(QVector3D(.5,0,.5),QVector3D(.25,.25,.25),QVector3D(.6,.6,.6),QVector3D(0,0,0),10);
//     Shapes * font_plane = new Square(QVector3D(50,-25,-10),QVector3D(50,25,-10),QVector3D(-50,25,-10),QVector3D(-50,-25,-10),p);
     this->objects.push_back(center_circle);
     this->objects.push_back(far_circle);
//     this->objects.push_back(c1);
//     this->objects.push_back(c2);
//     this->objects.push_back(c3);
//     this->objects.push_back(c4);
//     this->objects.push_back(c5);
//     this->objects.push_back(c6);
//     this->objects.push_back(c7);
//     this->objects.push_back(c8);
//     this->objects.push_back(c9);
     this->objects.push_back(bottom);
     this->objects.push_back(triangle);


     // this->objects.push_back(top_plane);
     //this->objects.push_back(back_plane);
    // this->objects.push_back(left_plane);
    // this->objects.push_back(right_plane);
    // this->objects.push_back(font_plane);
    // this->objects.push_back(pyramid);
     //Insert Lights



    Lights * light = new Lights(QVector3D(0.4,0.4,0.4),QVector3D(0,0,-2));
   // Lights * other_light = new Lights(QVector3D(0.2,0.2,0.2),QVector3D(3,0,-4));
    //Lights * third_light = new Lights(QVector3D(0.5,0,0.5),QVector3D(0,0,-5));
    this->lights.push_back(light);
  //  this->lights.push_back(other_light);
    //this->lights.push_back((third_light));

    //Lights * light_two = new Lights(QVector3D(1,1,1),QVector3D(5,-5,0));
   // this->lights.push_back((light_two));
}

