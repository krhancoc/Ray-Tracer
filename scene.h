#ifndef SCENE_H
#define SCENE_H
#include<vector>
#include<shapes.h>
#include<lights.h>
class Scene
{
public:
    Scene();
    std::vector<Shapes*> objects;
    std::vector<Lights*>lights;
    QVector3D ambient;
};

#endif // SCENE_H
