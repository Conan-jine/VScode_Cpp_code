#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

int sum=0,res;
int temp[10];
int arr[10000][10];

void dfs(int loc, int n)
{
    if(loc==10 && n==res)
    {
        sum++;
        for(int i=0;i<10;i++)   arr[sum-1][i]=temp[i];
        return;
    }
    if(loc>10 || n>res)   return;
    for(int i=1;i<4;i++)
    {   
        temp[loc]=i;
        dfs(loc+1,n+i);
    }
}

int main()
{
    cin>>res;
    dfs(0,0);
    cout<<sum<<endl;
    for(int i=0;i<sum;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j!=0)    printf(" ");
            printf("%d",arr[i][j]);
        }
        cout<<endl;
    }
    return 0;
}