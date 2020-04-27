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

Point scale(Point p, int fac) {
    Point pnew;
    pnew.X = p.X*fac;
    pnew.Y = p.Y*fac;
    return pnew;
}

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    Point p1(50,50),p2(100,100);
    Point p1New = scale(p1,2),p2New = scale(p2,2);
    rectangle(p1.X,p1.Y,p2.X,p2.Y);
    delay(2000);
    rectangle(p1New.X,p1New.Y,p2New.X,p2New.Y);
    int n;
    cin>>n;
    closegraph();
}