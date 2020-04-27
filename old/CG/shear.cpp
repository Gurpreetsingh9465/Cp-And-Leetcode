#include<iostream>

#include<graphics.h>
using namespace std;
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    float x1,y1,x2,y2;
    float shx,shy;
    char ch;
    x1=50;y1=100;x2=100;y2=200;
    rectangle(x1,y1,x2,y2);
    delay(10);
    cout<<"enter the direction of shear : ";
    cin>>ch;
    if(ch=='x') {
        cout<<"enter x-direction of shear : ";
        cin>>shx;
        y1=y1+shx*x1;
        y2=y2+shx*x2;
        setcolor(RED);
        rectangle(x1,y1,x2,y2);
    }
    else
    {
        cout<<"enter y-direction of shear : ";
        cin>>shy;
        x1=x1+shy*y1;
        x2=x2+shy*y2;
        setcolor(RED);
        rectangle(x1,y1,x2,y2);
    }
    int n;
    cin>>n;
    return 0;
    closegraph();
}

