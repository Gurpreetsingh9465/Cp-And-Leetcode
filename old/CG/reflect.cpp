#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void reflect(int *x, int *y) {
    int* temp = y;
    y = x;
    x = temp;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd,&gm,NULL);
    setcolor(_color::GREEN);
    rectangle(300,100,200,50);
    setcolor(_color::RED);
    rectangle(100,300,50,200);

    int n;
    cin>>n;
    closegraph();
}