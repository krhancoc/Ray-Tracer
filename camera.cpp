
#include <camera.h>

Camera::Camera(QVector3D camera_location,float imageWidth, float imageHeight, float viewWidth, float viewHeight)
{
    this->location = camera_location;
    this->view.width = viewWidth;
    this->view.height = viewHeight;
    this->imageplane.width = imageWidth;
    this->imageplane.height = imageHeight;
}

Ray Camera::projectRay(float x, float y)
{
    float viewx = x/imageplane.width;
    float viewy = y/imageplane.height;
    viewx = viewx * view.width;
    viewy = viewy * view.height;
    viewx = viewx - view.width/2;
    viewy = viewy - view.height/2;
    return Ray(QVector3D(viewx - location[0],viewy - location[1], 0 - location[2]),location);
}

