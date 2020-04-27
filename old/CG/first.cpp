#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
main()
{
	
	int gd=0,gm=5,i=0;
	initgraph(&gd,&gm,NULL);
	while(i!=640)
		{
		line(0,440,640,440);//road
		line(20+i,400,180+i,400);
		line(20+i,400,20+i,380);
		line(180+i,400,180+i,380);
		line(20+i,380,50+i,380);
		line(150+i,380,180+i,380);
		line(75+i,360,50+i,380);
		line(150+i,380,125+i,360);
		line(75+i,360,125+i,360);
		circle(50+i,420,20);
		circle(150+i,420,20);
		i++;
		delay(3);
		cleardevice();
	}
	closegraph();
}