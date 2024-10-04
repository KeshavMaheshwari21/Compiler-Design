// Translating the polygon
#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int n,xs[100],ys[100],i,ty,tx;

void draw();
void translate();

int main()
{
int gd = DETECT,gm;

printf("Enter the number of sides of polygon : ");
scanf("%d",&n);
printf("Enter the coordinates: x,y for each vertex ");
for(i=0;i<n;i++)
scanf("%d%d",&xs[i],&ys[i]);
printf("Enter the distance for the translation :");
scanf("%d%d",&tx,&ty);
initgraph(&gd,&gm,"C:\Turboc3\BGI");
setcolor(RED);
draw();
translate();
setcolor(YELLOW);
draw();
getch();
closegraph();
return 0;
}
void draw()
{
for(i=0;i<n;i++)
line(xs[i],ys[i],xs[(i+1)%n],ys[(i+1)%n]);
}
void translate()
{
for(i=0;i<n;i++)
{
xs[i]+=tx;
ys[i]+=ty;
}}

