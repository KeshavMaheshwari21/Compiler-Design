#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int n,xs[100],ys[100],i;
float sfy,sfx;

void draw();
void scale();

int main()
{
int gd = DETECT,gm;

printf("Enter the number of sides of polygon : ");
scanf("%d",&n);
printf("Enter the coordinates: x,y for each vertex ");
for(i=0;i<n;i++)
scanf("%d%d",&xs[i],&ys[i]);
printf("Enter the scaling factor :");
scanf("%d%d",&sfx,&sfy);
initgraph(&gd,&gm,"C:\Turboc3\BGI");
setcolor(RED);
draw();
scale();
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
void scale()
{
for(i=0;i<n;i++)
{
xs[i]+=xs[0]+(int)((float)(xs[i]-xs[0])*sfx);
ys[i]+=ys[0]+(int)((float)(ys[i]-ys[0])*sfy);
}}

