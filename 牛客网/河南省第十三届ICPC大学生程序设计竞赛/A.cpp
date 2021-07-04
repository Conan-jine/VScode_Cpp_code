#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n,m;
int arr[1010][1010];
int x,y;

int main()
{
    bool no=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   for(int j=1;j<=m;j++)   cin>>arr[i][j];
    cin>>x>>y;
    for(int i=1;i<=n-x+1;i++)
    {
        for(int j=1;j<=m-y+1;j++)
        {
            if(arr[i][j]==arr[i+x-1][j] && arr[i+x-1][j]==arr[i][j+y-1] && arr[i][j+y-1]==arr[i+x-1][j+y-1])
            {
                no=false;
                // for(int k=i+1;k<=i+x-2;k++)
                // {
                //     for(int l=j+1;l<=j+y-2;l++)
                //     {
                //         if(arr[k][l]>arr[i][j]) no=true;
                //         else    continue;
                //         if(no)  break;
                //     }
                //     if(no)  break;
                // }
                if(!no)
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    for(int i=1;i<=n-y+1;i++)
    {
        for(int j=1;j<=m-x+1;j++)
        {
            if(arr[i][j]==arr[i+y-1][j] && arr[i+y-1][j]==arr[i][j+x-1] && arr[i][j+x-1]==arr[i+y-1][j+x-1])
            {
                no=false;
                // for(int k=i+1;k<=i+y-2;k++)
                // {
                //     for(int l=j+1;l<=j+x-2;l++)
                //     {
                //         if(arr[k][l]>arr[i][j]) no=true;
                //         else    continue;
                //         if(no)  break;
                //     }
                //     if(no)  break;
                // }
                if(!no)
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}