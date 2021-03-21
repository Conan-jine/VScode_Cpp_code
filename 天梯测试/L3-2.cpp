#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool judge=false;
char arr[25][25];
int n;
int res[25];
bool vis[25];

void search(int i, int loc)
{
    // cout<<loc<<endl;
    if(judge || loc>=n)   return;
    if(loc==n-1)
    {
        if(arr[res[loc]][1]=='W' || arr[1][res[loc]]=='L')
        {
            judge=true;
            for(int i=0;i<n;i++)
            {
                if(i!=0)    cout<<' ';
                cout<<res[i];
            }
            cout<<endl;
        }
    }
    for(int j=1;j<=n && !judge;j++)
    {
        if( (arr[i][j]=='W' || arr[j][i]=='L') && !vis[j])
        {
            res[loc+1]=j;
            vis[j]=true;
            search(j,loc+1);
            vis[j]=false;
        }
    }
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)    for(int j=1;j<=n;j++)    cin>>arr[i][j];
    res[0]=1;
    search(1,0);
    if(!judge)
    {
        cout<<"No Solution"<<endl;
    }
    return 0;
}