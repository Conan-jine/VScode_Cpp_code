#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

int n;
bool temp[10];
int arr[10];

void dfs(int loc)
{
    if(loc==n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%5d",arr[i]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        if(temp[i]) continue;
        else
        {
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
    std::cin>>n;
    dfs(0);
    return 0;
}