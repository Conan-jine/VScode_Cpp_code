#include <iostream>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;

int minNum=100000000;
int n,arr[12][2];
bool visit[12]={0};

void dfs(int loc, int s, int b)
{
    if(loc>n)  return;
    if(abs(s-b)<minNum && loc!=0) minNum=abs(s-b);
    for(int i=0;i<n;i++)
    {
        if(visit[i])    continue;
        visit[i]=true;
        dfs(loc+1,s*arr[i][0],b+arr[i][1]);
        visit[i]=false;
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i][0]>>arr[i][1];
    dfs(0,1,0);
    cout<<minNum<<endl;
    return 0;
}