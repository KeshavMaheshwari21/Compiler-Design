#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void triangle(int x1,int y1,int x2,int y2,int x3,int y3);
void reflection(int x1,int y1,int x2,int y2,int x3,int y3);
void main()
{
    int gd=DETECT,gm;
    int x1,y1,x2,y2,x3,y3;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    printf("Enter the 1st point for the triangle:");
    scanf("%d%d",&x1,&y1);
    printf("Enter the 2nd point for the triangle:");
    scanf("%d%d",&x2,&y2);
    printf("Enter the 3rd point for the triangle:");
    scanf("%d%d",&x3,&y3);
    triangle(x1,y1,x2,y2,x3,y3);
    setcolor(1);
    getch();
    reflection(x1,y1,x2,y2,x3,y3);
    getch();
}
void triangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
   line(x1,y1,x2,y2);
   line(x2,y2,x3,y3);
   line(x3,y3,x1,y1);
}
void reflection(int x1,int y1,int x2,int y2,int x3,int y3)
{
   setcolor(RED);
   line(x1,-y1+400,x2,-y2+400);
   line(x2,-y2+400,x3,-y3+400);
   line(x3,-y3+400,x1,-y1+400);
}
