#include <iostream>
#include <iomanip>
#include <cstdio>

double n,r;
int temp[22];

void dfs(int num, int loc)
{
    if(n-temp[0]<=r-1) return;
    if(loc==r)
    {
        for(int i=0;i<r;i++)    printf("%3d",temp[i]);
        printf("\n");
        return;
    }
    for(int i=num+1;i<=n;i++)
    {
        temp[loc]=i;
        dfs(i,loc+1);
    }
    return;
}

int main()
{
    std::cin>>n>>r;
    dfs(0,0);
    for(int i=n-r+1;i<=n;i++)   printf("%3d",i);
    return 0;
}