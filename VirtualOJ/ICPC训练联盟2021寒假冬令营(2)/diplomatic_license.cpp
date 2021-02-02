#include <iostream>
#include <cstdio>

int main()
{
    int n;
    double beginX,beginY,lastX,lastY,nowX,nowY;
    while(scanf("%d",&n)==1)
    {
        printf("%d",n);
        scanf("%lf%lf",&beginX, &beginY);
        lastX=beginX;
        lastY=beginY;
        for(int i=0;i<n-1;i++)
        {
            scanf("%lf%lf",&nowX,&nowY);
            printf(" %.6lf %.6lf",(nowX+lastX)/double(2), (nowY+lastY)/double(2));
            lastX=nowX;
            lastY=nowY;
        }
        printf(" %.6lf %.6lf\n",(lastX+beginX)/double(2), (lastY+beginY)/double(2));
    }
}