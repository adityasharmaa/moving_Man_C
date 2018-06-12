#include<graphics.h>
#include<stdio.h>

int main()
{
    int gd=DETECT,gm,x=31,a=30,b=1,c=30,i,y,ry;
    initgraph(&gd,&gm,"");
    while(!kbhit())
    {
        for(i=1;i<=640;i+=10)
        {
            y=rand()%480;
            if(i>=x-59 && i<=x+148)
            y=rand()%275;
            line(i,y,i,y-4);
        }
        //umbrella
        arc(x+45,375,44,136,145);
        line(x-59,275,x+148,275);
        line(x+45,375,x+45,275);//handle
        floodfill(x+50,250,15);
        //head and trunk
        circle(x,350,30);
        floodfill(x,350,15);
        line(x,380,x,430);
        //legs
        line(x,430,x-a,480);
        line(x,430,x+a,480);

        line(x,390,x-c,430);// moving hand
        line(x,390,x+45,375);// steady hand

        x++;
        a-=b;
        c--;

        if(x==660)
        {x=-59;c=59;}

        if((x-1)%30==0)
        b=-b;

        if(((x-31)/60)%2!=0)
        c+=2;

        delay(20);
        cleardevice();
    }
    getch();
    closegraph();
    return 0;
}
