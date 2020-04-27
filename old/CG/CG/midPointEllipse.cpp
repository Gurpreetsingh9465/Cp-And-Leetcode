#include<graphics.h>
#include <bits/stdc++.h> 
using namespace std; 
  
void midptellipse(int rx, int ry,  
                  int xc, int yc)
{
    int color = _color::MAGENTA;
    float dx, dy, d1, d2, x, y; 
    x = 0; 
    y = ry; 
    d1 = (ry * ry) - (rx * rx * ry) +  
                     (0.25 * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 
    while (dx < dy)  
    {
        putpixel(x + xc,y+yc,color);
        putpixel(-x + xc,y+yc,color);
        putpixel(x + xc,-y+yc,color);
        putpixel(-x + xc,-y+yc,color);
        if (d1 < 0) 
        { 
            x++; 
            dx = dx + (2 * ry * ry); 
            d1 = d1 + dx + (ry * ry); 
        } 
        else 
        { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d1 = d1 + dx - dy + (ry * ry); 
        } 
    } 
  
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +  
         ((rx * rx) * ((y - 1) * (y - 1))) - 
          (rx * rx * ry * ry); 
    while (y >= 0) 
    { 
        putpixel(x + xc,y+yc,color);
        putpixel(-x + xc,y+yc,color);
        putpixel(x + xc,-y+yc,color);
        putpixel(-x + xc,-y+yc,color);
    
        if (d2 > 0)  
        { 
            y--; 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + (rx * rx) - dy; 
        } 
        else 
        { 
            y--; 
            x++; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + dx - dy + (rx * rx); 
        } 
    } 
} 

void flood(int x, int y, int &color) {
    if(color == 0)
        color+=1;
    if(x>=getmaxx() || y >= getmaxy() || x<0 || y < 0)
        return;
    if(getpixel(x,y) != _color::BLACK || getpixel(x,y) == color) {

        return;
    }
    putpixel(x,y,color);
    flood(x,y-1,color);
    flood(x,y+1,color);
    // flood(x+1,y+1,color);
    // flood(x+1,y-1,color);
    // flood(x-1,y-1,color);
    flood(x+1,y,color);
    flood(x-1,y,color);
    // flood(x-1,y+1,color);
    
}

main()
{
	int gd=0,gm=5;
	initgraph(&gd,&gm,NULL);
    int x = getmaxx();
    int y = getmaxy();
    // rectangle(x/2-50,y/2-50,x/2+50,y/2+50);
    midptellipse(200, 200, x/2,y/2);
    // midptellipse(201, 101, x/2,y/2);
    // midptellipse(202, 102, x/2,y/2);
    int color = _color::BLUE;
    // flood(x/2,y/2,color);
    int n;
    cin>>n;
	closegraph();
}