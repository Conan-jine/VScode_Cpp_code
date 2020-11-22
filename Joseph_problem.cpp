#include <iostream>
using namespace std;

int main()
{
    int arr[110];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)    arr[i]=i;
    int len=n,loc=0,ptr=0;
    cout<<arr[m];
    arr[m]=0;
    len--;
    loc=m;
    while(len!=1)
    {
        loc++;
        if(loc>n)   loc-=n;
        if(arr[loc]==0) continue;
        ptr++;
        if(ptr==m)
        {
            cout<<' '<<arr[loc];
            arr[loc]=0;
            len--;
            ptr=0;
        }
    }
    while(arr[loc]==0)
    {
        loc++;
        if(loc>n)   loc-=n;
    }
    cout<<' '<<arr[loc];
    return 0;
}