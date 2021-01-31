#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

int n,addNum,mark=0,sum=0;
bool judge=true,temp[10010],BREAK=false;
int arr[10010],now[10010];

void dfs(int loc)
{
    if(BREAK)   return;
    if(loc==n)
    {
        sum++;
        if(sum-1==addNum)
        {
            for(int i=0;i<n;i++)
            {
                if(i!=0)    printf(" ");
                printf("%d",arr[i]);
            }
            BREAK=true;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(temp[i]) continue;
        else
        {
            if(mark<n)
            {
                i=now[mark];
                mark++;
            }
            temp[i]=true;
            arr[loc]=i;
            dfs(loc+1);
            temp[i]=false;
        }
    }
    return;
}

int main()
{
    std::cin>>n>>addNum;
    for(int i=0;i<n;i++)    cin>>now[i];
    dfs(0);
    return 0;
}