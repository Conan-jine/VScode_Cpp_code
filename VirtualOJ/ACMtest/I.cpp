#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

char arr[120][120];
int n,m,cnt;
int addx[10]={-1,0,1,1,1,0,-1,-1};
int addy[10]={-1,-1,-1,0,1,1,1,0};

void clear(int x, int y)
{
    for(int i=0;i<8;i++)
    {
        if(arr[x+addx[i]][y+addy[i]]=='@')
        {
            arr[x+addx[i]][y+addy[i]]='*';
            clear(x+addx[i],y+addy[i]);
        }
        arr[x+addx[i]][y+addy[i]]='*';
    }
}

int main()
{
    while(cin>>n>>m)
    {
        cnt=0;
        memset(arr,'*',sizeof(arr));
        if(n==0 || m==0)    break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(arr[i][j]=='@')
                {
                    cnt++;
                    // cout<<cnt<<endl;
                    clear(i,j);
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}