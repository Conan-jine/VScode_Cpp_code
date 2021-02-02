#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char Map[120][120];
int n,m,len,sum=0;

void search(int x, int y, int loc, int ax, int ay)
{
    if(Map[x][y]=='#' || x==n || y==m)  return;
    if(loc==len)
    {
        // cout<<x<<' '<<y<<endl;
        sum++;
        return;
    }
    search(x+ax,y+ay,loc+1,ax,ay);
    return;
}

int main()
{
    cin>>n>>m>>len;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)    cin>>Map[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(len==1 && Map[i][j]!='#')
            {
                sum++;
                continue;
            }
            search(i,j,1,1,0);
            search(i,j,1,0,1);
        }
    }
    cout<<sum<<endl;
    return 0;
}