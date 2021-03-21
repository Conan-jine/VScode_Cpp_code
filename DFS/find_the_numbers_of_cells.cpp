#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char arr[120][120];
int cnt=0,n,m;
int ax[4]={-1,0,1,0};
int ay[4]={0,1,0,-1};

void dfs(int x, int y)
{
    arr[x][y]='0';
    for(int  i=0;i<4;i++)
    {
        if(x+ax[i]>=0 && x+ax[i]<n && y+ay[i]>=0 && y+ay[i]<m)
        {
            if(arr[x+ax[i]][y+ay[i]]!='0')  dfs(x+ax[i],y+ay[i]);
        }
    }
    return;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)    for(int j=0;j<m;j++)    cin>>arr[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]!='0')
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}