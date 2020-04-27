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

Point translate(Point p, int dis) {
    Point pnew;
    pnew.X = p.X+dis;
    pnew.Y = p.Y+dis;
    return pnew;
}

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    Point p1(200,300),p2(100,400);
    Point p1New = translate(p1,45),p2New = translate(p2,45);
    rectangle(p1.X,p1.Y,p2.X,p2.Y);
    delay(2000);
    rectangle(p1New.X,p1New.Y,p2New.X,p2New.Y);
    int n;
    cin>>n;
    closegraph();
}