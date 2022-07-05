#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Ray.h"
#include "Vector.h"
#include "Sphere.h"
#include "Plane.h"
#include "Color.h"
#include <list>
#include "Triangle.h"
#include "Torus.h"
#include "CheckerWall.h"

#define TRACEDEPTH		6

using namespace std;

class RayTracer
{
    private:
        list<Object *> mObjects;
        int mHeight;
        int mWidth;

        void TraceRay(Ray dir, int depth, Color& color);
        bool HasShadow(Vector origin, Vector dir, Object *hitObject);
        Color CalculateReflection(Vector hitPoint, Vector dir, Object *hitObject, int depth);
        Vector CalculateIntesectionPoint(Ray ray, double distance);
    public:
        RayTracer(int height, int width);
        ~RayTracer();
        void InitScene();
        unsigned char* Render();
};
#endif //RAYTRACER_H
