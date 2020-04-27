#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

class Point {
    public:
    int X, Y;
    Point() {}
    Point(int X, int Y) {
        this->X = X;
        this->Y = Y;
    }
};

Point rotate(Point p, int theta) {
    Point pnew;
    pnew.X = ceil(p.X*cos(0.0174533*p.X) - p.Y*sin(0.0174533*p.Y));
    pnew.Y = ceil(p.X*cos(0.0174533*p.X) - p.Y*sin(0.0174533*p.Y));
    return pnew;
}

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    Point p1(200,300),p2(100,300);
    Point p1New = rotate(p1,45);
    line(p2.X,p2.Y,p1.X,p1.Y);
    putpixel(p1.X,p1.Y,_color::GREEN);
    delay(2000);
    putpixel(p1New.X,p1New.Y,_color::RED);
    line(p2.X,p2.Y,p1New.X,p1New.Y);
    int n;
    cin>>n;
    closegraph();
}