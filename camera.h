#ifndef CAMERA
#define CAMERA
#include <QVector3D>
#include <ray.h>

typedef struct
{
    float width;
    float height;
} viewport;

typedef struct
{
   float width;
   float height;
}imagePlane;


class Camera {

public:

    QVector3D location;
    viewport view;
    imagePlane imageplane;

    Camera(QVector3D camera_location,float imageWidth, float imageHeight, float viewWidth, float viewHeight);
    Ray projectRay(float x, float y);
private:

};

#endif // CAMERA
