#include "RayTracer.h"
#include <iostream>

RayTracer::RayTracer(int height, int width):
                     mHeight(height), mWidth(width)
{

}

RayTracer::~RayTracer()
{

}

void RayTracer::InitScene()
{

    CheckerWall floor(6,10,2);
    mObjects = floor.GetObjects();
/*
    Torus *a = new Torus("Torus", false, 2.0, 0.4);
    a->SetColor(Color(0.45,0.23,0.9));
    a->Diffuse(0.035);
    mObjects.push_front(a);

    Sphere *sphereA = new Sphere("BlueBall", false, Vector(0,0,0),0.75);
    sphereA->SetColor(Color(1.0,1,1));
    sphereA->Reflective(1);
    mObjects.push_front(sphereA);

    Vector A(0,-1,2);
    Vector B(0,-1,0);
    Vector C(2,-1,0);
    Vector D(2,-1,2);

    Triangle *test = new Triangle("Tri", false, D,B,A);
    //test->SetColor(Color(0.45,0.23,0.9));
    test->SetColor(Color(1,1,1));
    test->Diffuse(0.75);
    mObjects.push_front(test);

    Triangle *test1 = new Triangle("Tria", false, D,C,B);
    //test1->SetColor(Color(0.50,0.53,0.2));
    test1->SetColor(Color(1,1,1));
    test1->Diffuse(0.75);
    mObjects.push_front(test1);

    Sphere *middleSphere = new Sphere("RedBall", false,Vector(0,-2,0),0.5);
    //middleSphere->SetColor(Color(0.45,0.23,0.9));
    middleSphere->SetColor(Color(0.7,0.7,0.7));
    middleSphere->Diffuse(0.5);
//    middleSphere->Reflective(0.6);
    mObjects.push_front(middleSphere);
*/
    Sphere *middleSphere = new Sphere("RedBall", false,Vector(-1,0,10),2.0);
    //middleSphere->SetColor(Color(0.45,0.23,0.9));
    middleSphere->SetColor(Color(0.7,0.7,0.7));
    //middleSphere->Diffuse(0.25);
    middleSphere->Reflective(0.6);
    mObjects.push_front(middleSphere);
/*
    Sphere *sphereA = new Sphere("BlueBall", false, Vector(-1,4.33,8),2.0);
    sphereA->SetColor(Color(1.0,0.945,0.246));
    sphereA->Diffuse(0.25);
    mObjects.push_front(sphereA);

    Sphere *sphere = new Sphere("GreenBall", false,Vector( -1, -2.5, 4),2.0);
    sphere->SetColor(Color(0.34,0.89,0.02));
    sphere->Diffuse(0.35);
    mObjects.push_front(sphere);

    Sphere *sphereB = new Sphere("MirrorBall", false,Vector( 3,-3.5, 4), 0.5);
    sphereB->SetColor(Color(0.7,0.7,1.0));
    sphereB->Diffuse(0.25);
    sphereB->Reflective(0.25);
    mObjects.push_front(sphereB);

    Plane *a_plane = new Plane("floor", false, Vector(0,1,0), 3);
    //a_plane->SetColor(Color(0.56,0.12,0.67));
    a_plane->SetColor(Color(1.,1.,1.));
    a_plane->Diffuse(0.55);
    mObjects.push_front(a_plane);

    Plane *b_plane = new Plane("backWall", false, Vector(0,0,-1), 20);
    b_plane->SetColor(Color(0.72,0.54,0.71));
    //b_plane->SetColor(Color(1.0,1.0,1.0));
    b_plane->Diffuse(0.45);
    mObjects.push_front(b_plane);
*/
    Sphere *lighta = new Sphere("Light2", true, Vector(12,12,6),1.0);
    lighta->SetColor(Color(1.0,1.0,1.0));
    mObjects.push_front(lighta);

    Sphere *light = new Sphere("Light", true, Vector(6,18,-15), 1.0);
    light->SetColor(Color(1.0,1.0,1.0));
    mObjects.push_front(light);

    std::cout << mObjects.size() << " Primitives" << std::endl;

}

unsigned char* RayTracer::Render()
{
    unsigned char *image = (unsigned char *)malloc(mHeight * mWidth * 3); 
    //STEP:: set up view
    Vector eye(0,0,-10);
    int count = 0;

    for(int x = 0; x < mWidth; x++)
    {
        for(int y = 0; y < mHeight; y++)
        {
            double size = 10.0;
            double px = (double)x / (double)mWidth * size - size / 2.0;
            double py = (double)y / (double)mHeight * size - size / 2.0;

            Color pixelColor(0,0,0);
            Vector dir( py, px, 0 );
            dir = dir - eye;
            dir = dir.Normalize();
            Ray ray(eye, dir);

            TraceRay(ray, 0, pixelColor);

            image[count++] = (int)(pixelColor.Red() * 255);
            image[count++] = (int)(pixelColor.Green() * 255);
            image[count++] = (int)(pixelColor.Blue() * 255);
        }
    }

    return image; 
}

void RayTracer::TraceRay(Ray dir, int depth, Color& value)
{
    if( depth > TRACEDEPTH) return ;

    double distance = 99999999;
    Object *hitObject = 0;

    for(list<Object *>::iterator it = mObjects.begin(); it != mObjects.end(); it++)
    {
        double hitDistance = 0;
        bool hit = (*it)->Intersect(dir, hitDistance);
        if(hit)
        {
            if(hitDistance < distance)
            {
                distance = hitDistance;
                hitObject = *it;
            }
        }
    }
  
    //NO hit return black;  
    if(!hitObject || distance < 0)
    {
        value = Color(0,0,0);
        return;
    }

    if(hitObject->IsLight() == true)
    {
        value = Color(1.,1.,1.);
        return;
    }

    Vector pointHit = dir.GetOrigin() + dir.GetDirection() * distance;
    for(list<Object *>::iterator it = mObjects.begin(); it != mObjects.end(); it++)
    {
        if((*it)->IsLight())
        {
            if(HasShadow(pointHit, ((Sphere*)(*it))->GetCenter(), hitObject) == true)
            {
                //Do nothing
            }
            else
            {
                Vector L = ((Sphere*)(*it))->GetCenter() - pointHit;
                L = L.Normalize();
                Vector N = hitObject->GetNormal(pointHit);

                double dot = N.Dot(L); 
                double diff = dot * hitObject->GetDiffuse();

			    if(diff >0)
                {  
                    Color lightColor((*it)->GetColor());
                    Color hitColor(hitObject->GetColor());
                    Color temp(lightColor * hitColor * diff); 
                    value += temp;
                }
            }            
        }
        if(hitObject->GetReflective() > 0)
        {
            Color color(0,0,0);
            color = CalculateReflection(pointHit,   dir.GetDirection() , hitObject, depth);
            //Color hitColor(hitObject->GetColor());
            //Color tmp ( color * hitObject->GetReflective() * hitColor);            

            value = color;
        }
    }
}

bool RayTracer::HasShadow(Vector origin, Vector dir, Object *base)
{
    //dir = origin - dir;
    dir = dir - origin; 
    dir = dir.Normalize();
    Ray ray(origin, dir);

    double distance = 99999999;
    Object *hitObject = 0;

    for(list<Object *>::iterator it = mObjects.begin(); it != mObjects.end(); it++)
    {
        if(base == (*it))
            continue;

        double hitDistance = 0;
        bool hit = (*it)->Intersect(ray, hitDistance);
        if(hit)
        {
            if(hitDistance < distance && hitDistance > 0)
            {
                distance = hitDistance;
                hitObject = *it;
            }
        }
    }

    if(!hitObject)
        return false;

    if(hitObject->IsLight() == false)
        return true;

    return false;
}

Color RayTracer::CalculateReflection(Vector pointHit, Vector dir, Object *hitObject, int depth)
{
    //Step Calacuate R = I - 2(N*I)N
    // I is the incident ray
    // N is the surface ray
    // R is the relected ray

    Vector N = hitObject->GetNormal(pointHit);
    double tmp = 2 * N.Dot(dir);
    Vector woot = N * tmp;
    Vector R = dir - woot;
    Color returnColor(0,0,0);
    if( depth < TRACEDEPTH)
    {
        Vector orgin(pointHit + R * 0.0006);
        Ray newEye(orgin, R);
        TraceRay(newEye, depth++, returnColor);
    }

    double dot = N.Dot(R);
    if(dot > 0)
    {
        double spec = pow(dot,2) * 0.85;
        returnColor *= spec;
    }
 
    return returnColor;
}
