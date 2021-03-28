#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int arr[120];
    int len,t;
    double n,cost;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>cost;
        if(cost<n-1 || cost>(n-1)/2*(n+2))
        {
            cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
            continue;
        }
        for(int j=1;j<=n;j++)   arr[j]=j;
        cost-=n-1;
        for(int j=n-1;j>=1;j--)
        {
            len=std::min(n-j,cost);
            cost-=len;
            for(int k=0;j+k<j+len-k;k++)    std::swap(arr[j+k],arr[j+len-k]);
        }
        cout<<"Case #"<<i<<": ";
        for(int j=1;j<=n;j++)
        {
            cout<<arr[j];
            if(j!=n)    cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}