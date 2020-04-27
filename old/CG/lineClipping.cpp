#include<stdio.h>
#include<graphics.h>

void pointClip(int XY[][2], int n, int Xmin, int Ymin,
                                   int Xmax, int Ymax)
{

    int gm,gd=DETECT;
    initgraph(&gd,&gm,NULL);
    outtextxy(400,10,(char *)"BEFORE CLIPPING");
    rectangle(Xmin,Ymin,Xmax,Ymax);
    for(int j=0; j<n; j++)
    {
        putpixel(XY[j][0],XY[j][1],WHITE);
        putpixel(XY[j][0]+1,XY[j][1],WHITE);
        putpixel(XY[j][0],XY[j][1]+1,WHITE);
        putpixel(XY[j][0]+1,XY[j][1]+1,WHITE);
        putpixel(XY[j][0]-1,XY[j][1],WHITE);
        putpixel(XY[j][0],XY[j][1]-1,WHITE);
        putpixel(XY[j][0]-1,XY[j][1]-1,WHITE);
        putpixel(XY[j][0]-1,XY[j][1]+1,WHITE);
        putpixel(XY[j][0]+1,XY[j][1]-1,WHITE);
    }
    delay(5000);
    closegraph();
    initgraph(&gd,&gm,NULL);
    outtextxy(400,10,(char *)"AFTER CLIPPING");
    rectangle(Xmin,Ymin,Xmax,Ymax);
    for (int i=0; i<n; i++)
    {
    if ( (XY[i][0] >= Xmin) && (XY[i][0] <= Xmax))
    {
            if ( (XY[i][1] >= Ymin) && (XY[i][1] <= Ymax))
        {
            putpixel(XY[i][0],XY[i][1],WHITE);
            putpixel(XY[i][0]+1,XY[i][1],WHITE);
            putpixel(XY[i][0],XY[i][1]+1,WHITE);
            putpixel(XY[i][0]+1,XY[i][1]+1,WHITE);
            putpixel(XY[i][0]-1,XY[i][1],WHITE);
            putpixel(XY[i][0],XY[i][1]-1,WHITE);
            putpixel(XY[i][0]-1,XY[i][1]-1,WHITE);
            putpixel(XY[i][0]-1,XY[i][1]+1,WHITE);
            putpixel(XY[i][0]+1,XY[i][1]-1,WHITE);



        }
    }
    }
    delay(30000);
    closegraph();

   
}

int main()
{
    int XY[6][2] = {{100,60}, {100,10}, {300,100},
                    {100,400}, {60,60}, {100,40}};

    // getmaxx() & getmaxy() will return Xmax, Ymax
    // value if graphics.h is included
    int Xmin = 50;
    int Xmax = 350;
    int Ymin = 50;
    int Ymax = 350;
    pointClip(XY, 6,  Xmin, Ymin, Xmax, Ymax);
    return 0;
}