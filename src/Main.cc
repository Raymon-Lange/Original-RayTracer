#include "Main.h"
#include "RayTracer.h"
#include <iostream>
#include "Maths.h"

void saveBitmap( const char *filename, int w, int h, const unsigned char *bitmap )
{
    FILE * f;
    int filesize = 54 + 3 * w * h;

    unsigned char bmpfileheader[ 14 ] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    unsigned char bmpinfoheader[ 40 ] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};

    bmpfileheader[ 2 ] = ( unsigned char ) ( filesize );
    bmpfileheader[ 3 ] = ( unsigned char ) ( filesize >> 8 );
    bmpfileheader[ 4 ] = ( unsigned char ) ( filesize >> 16 );
    bmpfileheader[ 5 ] = ( unsigned char ) ( filesize >> 24 );

    bmpinfoheader[ 4 ] = ( unsigned char ) ( w );
    bmpinfoheader[ 5 ] = ( unsigned char ) ( w >> 8 );
    bmpinfoheader[ 6 ] = ( unsigned char ) ( w >> 16 );
    bmpinfoheader[ 7 ] = ( unsigned char ) ( w >> 24 );
    bmpinfoheader[ 8 ] = ( unsigned char ) ( h );
    bmpinfoheader[ 9 ] = ( unsigned char ) ( h >> 8 );
    bmpinfoheader[ 10 ] = ( unsigned char ) ( h >> 16 );
    bmpinfoheader[ 11 ] = ( unsigned char ) ( h >> 24 );

    f = fopen( filename, "wb" );
    fwrite( bmpfileheader, 1, 14, f );
    fwrite( bmpinfoheader, 1, 40, f );
    fwrite( bitmap, 3, w * h, f );

    fclose( f );
}

int main(int ac, char *av[])
{
    int x = 512;
    const unsigned char *woot;
    RayTracer test(x,x);
    test.InitScene();
    woot = test.Render();
    saveBitmap("test.bmp", x,x,woot);
    return 0;   
}
