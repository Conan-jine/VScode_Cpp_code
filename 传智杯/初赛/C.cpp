#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct stu
{
    int t;
    int h;
    int sum;
    int loc;
}Stu[500010];

bool cmp(stu a, stu b)
{
    if(a.sum==b.sum)
    {
        if(a.t==b.t)    return a.loc<b.loc;
        return a.t>b.t;
    }
    else    return a.sum>b.sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&Stu[i].t,&Stu[i].h);
        Stu[i].sum=Stu[i].t*Stu[i].h;
        Stu[i].loc=i+1;
    }
    sort(Stu,Stu+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(i!=0)    printf(" ");
        printf("%d",Stu[i].loc);
    }
    return 0;
}