#include <iostream>
#include <algorithm>
using namespace std;

struct milk
{
    int each;
    int num;
}arr[5010];

bool cmp(milk a, milk b)
{
    return a.each < b.each;
}

int main()
{
    int m,n,cost=0;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].each>>arr[i].num;
    }
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(m>arr[i].num)
        {
            cost+=arr[i].each*arr[i].num;
            m-=arr[i].num;
        }
        else
        {
            cost+=arr[i].each*m;
            m=0;
            break;
        }
    }
    cout<<cost<<endl;
}