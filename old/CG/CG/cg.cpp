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
    pnew.X = ceil(p.X*cos(0.0174533*p.X) - p.Y*sin(0.0174533*p.Y));
    return pnew;
}

int main() {
    Point p1(200,300),p2(400,200);
    Point p1New = rotate(p1,60),p2New = rotate(p2,60);
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);
    rectangle(p1.X,p1.Y,p2.X,p2.Y);
    rectangle(p1New.X,p1New.Y,p2New.X,p2New.Y);
    int n;
    cin>>n;
    closegraph();
}