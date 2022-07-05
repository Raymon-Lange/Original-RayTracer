#include "CheckerWall.h"
#include "Triangle.h"

CheckerWall::CheckerWall(int columns, int rows, int height):
             mColumns(columns),mRows(rows), mHeight(height)
{
    Vector startLoc(-5,-3,-10);

    for(int x = 0; x < columns ; x++)
    {
        for(int z = 0; z < rows; z++)
        {
            double y = startLoc.Y();
            
            //STEP: Calc bottom left 
            double blx = startLoc.X() + (double)(x * mHeight);
            double blz = startLoc.Z() + (double)(z * mHeight);
            Vector B(blx, y, blz);

            //STEP: Calc bottom right
            double brx = startLoc.X() + (double)((x+1) * mHeight);
            double brz = startLoc.Z() + (double)(z * mHeight);
            Vector C(brx, y, brz);

            //STEP: Calc top left
            double tlx = startLoc.X() + (double)(x * mHeight);
            double tlz = startLoc.Z() + (double)((z+1) * mHeight);
            Vector A(tlx,y,tlz);

            //STEP: Calc top right
            double trx = startLoc.X() + (double)((x+1) * mHeight);
            double trz = startLoc.Z() + (double)((z+1) * mHeight);
            Vector D(trx, y, trz);

            //std::cout << "A " << A.X() << " : " << A.Y() << " : " << A.Z() << std::endl;
            //std::cout << "B " << B.X() << " : " << B.Y() << " : " << B.Z() << std::endl;
            //std::cout << "C " << C.X() << " : " << C.Y() << " : " << C.Z() << std::endl;
            //std::cout << "D " << D.X() << " : " << D.Y() << " : " << D.Z() << std::endl;

            Triangle *one = new Triangle("one", false, D, B, A);
            Triangle *two = new Triangle("two", false, D, C, B); 

            double color = (x + z) % 2;
            
            one->SetColor(Color(color, color, color));
            one->Diffuse(1);
            two->SetColor(Color(color, color, color));
            two->Diffuse(1);
            
            mObjects.push_front(one);
            mObjects.push_front(two);
        }
    } 
}

CheckerWall::~CheckerWall(){};

list<Object *> CheckerWall::GetObjects()
{
    return mObjects;
}

