#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char arr[120][120];
int n,m,sum=0;

void dfs(int x, int y)
{
    int nowX,nowY;
    arr[x][y]='.';
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            nowX=x+i;
            nowY=y+j;
            if(nowX>=0 && nowX<n && nowY>=0 && nowY<m)
            {
                if(arr[nowX][nowY]=='W')    dfs(nowX,nowY);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)    for(int j=0;j<m;j++)    cin>>arr[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='W')
            {
                dfs(i,j);
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}