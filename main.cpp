#include <QImage>
#include <camera.h>
#include <QVector3D>
#include <scene.h>
#include <tracer.h>
#include <cmath>
#include <iostream>
#define MIN 0.01;
#define AMB 0.2;

int main(int argc, char *argv[])
{
	// currently unused parameters
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	// image width and height
	// TODO: prompt user on command line for dimensions
    int width = 1024;
    int height = 1024;

	// create new image
	QImage image(width, height, QImage::Format_RGB32);

    //Create Camera
    Camera camera = Camera(QVector3D(0,0,-5),width,height,10,10);
    //Create Tracer Set BG Color
    Tracer tracer = Tracer(Scene());
    bool aa = false;
	// iterate over the pixels & set colour values
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            QVector3D avg;

            Ray ray = camera.projectRay(x,y);
            QVector3D color = tracer.trace(ray,15);
            bool ryan_at_6_am_mode = true;
            float delta = 0.01;
            if(ryan_at_6_am_mode) delta = .5;


            if(aa) {
                float camx = camera.location[0];
                float camy = camera.location[1];
                float camz = camera.location[2];

                camera.location[0] = camera.location[0] + delta;
                Ray r2 = camera.projectRay(x,y);
                QVector3D color2 = tracer.trace(r2,15);

                camera.location[1] = camera.location[1] + delta;
                Ray r3 = camera.projectRay(x,y);
                QVector3D color3 = tracer.trace(r3,15);

                camera.location[2] = camera.location[2] + delta;
                Ray r4 = camera.projectRay(x,y);
                QVector3D color4 = tracer.trace(r4,15);

                avg = 0.25*(color + color2 + color3 + color4);

                camera.location[0] = camx;
                camera.location[1] = camy;
                camera.location[2] = camz;

            }
            if(aa) image.setPixel(x, y,qRgb(avg[0] * 255, avg[1] * 255, avg[2] * 255));
            else image.setPixel(x, y,qRgb(color[0] * 255, color[1] * 255, color[2] * 255));


        }
    }

    // save to file
    // TODO: prompt user on command line for output name
    image.save("output.png");

    // application successfully returned
    return 0;
}
