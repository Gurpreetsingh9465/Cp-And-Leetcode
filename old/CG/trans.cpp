#include<bits/stdc++.h> 
#include<graphics.h> 
using namespace std;

void rotate(int x, int y, int x2, int y2, int theta) {
    float costheta = cos(0.0174*theta);
    float sintheta = sin(0.0174*theta);
    int x_ = x*costheta-y*sintheta;
    int y_ = x*costheta+y*sintheta;
    int x2_ = x2*costheta-y2*sintheta;
    int y2_ = x2*costheta+y2*sintheta;
    rectangle(abs(x_),abs(y_),abs(x2_),abs(y2_));
}

void translation(int &x, int &y, int p1, int p2) {
    x+=p1;
    y+=p2;
}


int main() 
{
    int gd = DETECT, gm;
    initgraph (&gd, &gm, NULL);
    // int x = 50;
    // int y = 50;
    // int x2 = 150;
    // int y2 = 100;
    // rectangle(x,y,x2,y2);
    // // translation(x,y,50,50);
    // // translation(x2,y2,50,50);
    // rotate(x,y,x2,y2,90);

    // // rotate(0,0,150,100,30);

    putpixel(0,0,5);
   
    int n;
    cin>>n;
    return 0; 
}  