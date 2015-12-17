#ifndef LIGHTS_H
#define LIGHTS_H

#include <QColor>
#include <QVector3D>

class Lights
{
public:
    Lights(QVector3D color, QVector3D position);
    QVector3D color;
    QVector3D position;
};

#endif // LIGHTS_H
