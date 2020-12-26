#include <iostream>
using namespace std;

int arr[510][510];
int tmp[510][510];

void fun(int x,int y,int r,int z)
{
    int n=2*r+1,t;
    int mx=1,my=1;
    for(int i=x-r;i<=x+r;i++)
    {
        my=1;
        for(int j=y-r;j<=y+r;j++)
        {
            tmp[mx][my]=arr[i][j];
            my++;
        }
        mx++;
    }
    if(z==0)
    {
        for(int i=1;i<=n/2;i++)
        {
            for(int j=i;j<n-i+1;j++)
            {
                t=tmp[i][j];
                tmp[i][j]=tmp[n-j+1][i];
                tmp[n-j+1][i]=tmp[n-i+1][n-j+1];
                tmp[n-i+1][n-j+1]=tmp[j][n-i+1];
                tmp[j][n-i+1]=t;
            }
        }
    }
    else
    {
        for(int i=1;i<=n/2;i++)
        {
            for(int j=i;j<n-i+1;j++)
            {
                t=tmp[i][j];
                tmp[i][j]=tmp[j][n-i+1];
                tmp[j][n-i+1]=tmp[n-i+1][n-j+1];
                tmp[n-i+1][n-j+1]=tmp[n-j+1][i];
                tmp[n-j+1][i]=t;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[x-r+i][y-r+j]=tmp[i+1][j+1];
        }
    }
}

int main()
{
    int t=1,n,m;
    int x,y,r,z;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   for(int j=1;j<=n;j++)   arr[i][j]=t++;
    while(m--)
    {
        cin>>x>>y>>r>>z;
        fun(x,y,r,z);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=1)    cout<<' ';
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}