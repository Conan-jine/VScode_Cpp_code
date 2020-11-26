#include <iostream>
using namespace std;
bool arr[10][10];
bool loc[10][10];
bool wb[100],wc[100],wd[100];
bool bb[100],bc[100],bd[100];
int n,all=0;

void dfs_black(int i)
{
    if(i==n+1)  all++;
    else
    {
        for(int j=1;j<=n;j++)
        {
            if( arr[i][j] && (!bb[j]) && (!bc[i+j]) && (!bd[i-j+n]) && (!loc[i][j]))
            {
                bb[j]=true;
                bc[i+j]=true;
                bd[i-j+n]=true;
                dfs_black(i+1);
                bb[j]=false;
                bc[i+j]=false;
                bd[i-j+n]=false;
            }
        }
    }
}

void dfs_white(int i)
{
    if(i==n+1)  dfs_black(1);
    else
    {
        for(int j=1;j<=n;j++)
        {
            if( arr[i][j] && (!wb[j]) && (!wc[i+j]) && (!wd[i-j+n]))
            {
                wb[j]=true;
                wc[i+j]=true;
                wd[i-j+n]=true;
                loc[i][j]=true;
                dfs_white(i+1);
                wb[j]=false;
                wc[i+j]=false;
                wd[i-j+n]=false;
                loc[i][j]=false;
            }
        }
    }
    return;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
    }
    dfs_white(1);
    cout<<all<<endl;
}