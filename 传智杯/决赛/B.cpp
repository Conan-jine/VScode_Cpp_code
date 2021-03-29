#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n,k;
long long arr[1200];

int main()
{
    int cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)    cin>>arr[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(arr[i]*arr[j]<=k)    cnt++;   
        }
    }
    cout<<cnt<<endl;
    return 0;
}