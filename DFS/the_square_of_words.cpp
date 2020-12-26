#include <iostream>
#include <string>
using namespace std;

int n;
string sample="yizhong";
int arr[110][110]={0};
char str[110][110];

bool dfs(int x,int y,int t,int c)
{
    if(t==7)    return true;
    if(x<0||x>=n||y<0||y>=n)    return false;
    if(c==1&&str[x][y]==sample[t])
    {
        if(dfs(x-1,y,t+1,1))
        {
            arr[x][y]=1;
            return 1;
        }
    }
    else if(c==2&&str[x][y]==sample[t])
    {
        if(dfs(x-1,y+1,t+1,2))    
        {
            arr[x][y]=1;
            return 1;
        }
    }
    else if(c==3&&str[x][y]==sample[t])
    {
        if(dfs(x,y+1,t+1,3))    
        {
            arr[x][y]=1;
            return 1;
        }
    }
    else if(c==4&&str[x][y]==sample[t])
    {
        if(dfs(x+1,y+1,t+1,4))    
        {
            arr[x][y]=1;
            return 1;
        }
    }
    else if(c==5&&str[x][y]==sample[t])
    {
        if(dfs(x+1,y,t+1,5))    
        {
            arr[x][y]=1;
            return 1;
        }
    }
    else if(c==6&&str[x][y]==sample[t])
    {
        if(dfs(x+1,y-1,t+1,6))    
        {
            arr[x][y]=1;
            return 1;
        }
    }
    else if(c==7&&str[x][y]==sample[t])
    {
        if(dfs(x,y-1,t+1,7))    
        {
            arr[x][y]=1;
            return 1;
        }
    }
    else if(c==8&&str[x][y]==sample[t])
    {
        if(dfs(x-1,y-1,t+1,8))    
        {
            arr[x][y]=1;
            return 1;
        }
    }
    return false;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>str[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dfs(i,j,0,1);
            dfs(i,j,0,2);
            dfs(i,j,0,3);
            dfs(i,j,0,4);
            dfs(i,j,0,5);
            dfs(i,j,0,6);
            dfs(i,j,0,7);
            dfs(i,j,0,8);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)    cout<<str[i][j];
            else    cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}