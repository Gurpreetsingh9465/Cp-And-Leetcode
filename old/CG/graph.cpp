#include<graphics.h>
#include <bits/stdc++.h> 
using namespace std;

void barGraph(vector<int> v) {
    int len = v.size();
    int maxx = getmaxx();
    int maxy = getmaxy();
    cout<<maxy;
    int width = maxx/len;
    int st = 0;
    for(auto &i: v) {
        int yval = (int)((float)maxy-(float(i*maxy)/100));
        rectangle(st,yval,st+width,maxy);
        st+=width;
    }
}

main()
{
	
	int gd=0,gm=5,i=0;
	initgraph(&gd,&gm,NULL);
    int x,y;
    vector<int> v = {200,150,250,449,10,5,1,2,10,12,15,20,26};
    barGraph(v);
    
	int n;
    cin>>n;
	closegraph();
}