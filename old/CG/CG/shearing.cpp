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

Point shear(Point p, int sh, char along) {
    Point pnew(0,0);
    if(along == 'X') {
        pnew.X = p.X+sh*p.Y;
        pnew.Y = p.Y;
    } else if(along == 'Y') {
        pnew.X = p.X;
        pnew.Y = p.Y+sh*p.X;

    }
    return pnew;
}

int main() {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    Point p1(100,200),p2(300,400);
    Point p1New = shear(p1,1,'X'),p2New = shear(p2,1,'X');
    rectangle(p1.X,p1.Y,p2.X,p2.Y);
    delay(2000);
    rectangle(p1New.X,p1New.Y,p2New.X,p2New.Y);
    int n;
    cin>>n;
    closegraph();
}