#include <iostream>
using namespace std;

struct stu
{
    double x;
    double y;
};

stu people[1100];
int MINR=1000;
int n,locx,locy;
double morw,lowx,lowy=100099;

void judge(double tx, double ty)
{
    if(lowx==tx && lowy==ty)    return;
    int left_m=0,left_w=0,right_m=0,right_w=0;
    double k=(ty-lowy)/(tx-lowx);
    for(int i=0;i<n;i++)
    {
        if(people[i].x<people[i].y/k) left_m++;
        else if(people[i].x>people[i].y/k)    right_m++;
    }
    for(int i=n;i<2*n;i++)
    {
        if(people[i].x<people[i].y/k) left_w++;
        else if(people[i].x>people[i].y/k)    right_w++;
    }
    if(left_m!=left_m || right_m!=right_w)  return;
    if(right_m+right_w<MINR)
    {
        MINR=right_m+right_w;
        locx=tx;
        locy=ty;
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>people[i].x>>people[i].y;
        if(people[i].y<lowy)
        {
            lowx=people[i].x;
            lowy=people[i].y;
            if(i<n) morw=1;
            else    morw=0;
            
            
        }
    }
    if(morw==1)
    {
        for(int i=n;i<2*n;i++)  judge(people[i].x,people[i].y);
    }
    else
    {
        for(int i=0;i<n;i++)    judge(people[i].x,people[i].y);
    }
    if(lowy==100099)    cout<<"NULL";
    else
    {
        for(int i=0;i<2*n;i++)
        {
            if(people[i].x==locx && people[i].y==locy)
            {
                cout<<i+1;
                break;
            }
        }
    }
    return 0;
}