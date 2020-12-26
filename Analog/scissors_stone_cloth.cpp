#include <iostream>
using namespace std;

int main()
{
    int arr[5][5]=
    {
        {0,-1,1,1,-1},
        {1,0,-1,1,-1},
        {-1,1,0,-1,1},
        {-1,-1,1,0,1},
        {1,1,-1,-1,0}
    };
    int t,n,m;
    int str1[210],str2[210];
    cin>>t>>n>>m;
    for(int i=0;i<n;i++)    cin>>str1[i];
    for(int i=0;i<m;i++)    cin>>str2[i];
    int sum1=0,sum2=0,x=0,y=0;
    while(t--)
    {
        if(arr[str1[x]][str2[y]]==1)    sum1++;
        else if(arr[str1[x]][str2[y]]==-1)  sum2++;
        x++;
        y++;
        if(x==n)    x-=n;
        if(y==m)    y-=m;
    }
    cout<<sum1<<' '<<sum2<<endl;
    return 0;
}