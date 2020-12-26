#include <iostream>
using namespace std;

int visit[10][10]={0};
int arr[10][10]={0};
int n,m,bx,by,ex,ey,sum=0;

void dfs(int x,int y)
{
    if(x<1||y<1||x>n||y>m||visit[x][y]==1)    return;
    if(x==ex&&y==ey)
    {
        sum++;
        return;
    }
    visit[x][y]=1;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
    visit[x][y]=0;
    return;
}

int main()
{
    int x,y,T;
    cin>>n>>m>>T;
    cin>>bx>>by>>ex>>ey;
    while(T--)
    {
        cin>>x>>y;
        visit[x][y]=1;
    }
    dfs(bx,by);
    cout<<sum<<endl;
}