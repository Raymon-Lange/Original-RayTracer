#ifndef CHECKERWALL_H 
#define CHECKERWALL_H

#include "Object.h"
#include <list>
using namespace std;

class CheckerWall
{
    private:
        int mColumns;
        int mRows;
        int mHeight;
        list<Object *> mObjects;
    public:
        CheckerWall(int columns, int rows, int height);
        ~CheckerWall();
        list<Object *> GetObjects();
};
#endif //CHECKEALL_H
