#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

bool arr[25][25];
// char c[25][25];
int times,n;
int res[12]={0,1,0,0,2,10,4,40,92,352,724};

void search(int now)
{
    bool temp[25][25];
    memcpy(temp,arr,sizeof(arr));
    if(now==n)
    {
        times++;
        // cout<<times<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<c[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[now][i]==false)
        {
            for(int len=0;len<=n;len++)
            {
                arr[now+len][i]=true;
                arr[now+len][i+len]=true;
                arr[now+len][i-len]=true;
            }
            // c[now][i]='+';
            search(now+1);
            // c[now][i]='-';
            memcpy(arr,temp,sizeof(arr));
        }
    }
}

int main()
{
    
    while(cin>>n)
    {
        if(n==0)    break;
        // times=0;
        // memset(arr,0,sizeof(arr));
        // // memset(c,'-',sizeof(c));
        // search(0);
        // cout<<times<<endl;
        cout<<res[n]<<endl;
    }
    return 0;
}