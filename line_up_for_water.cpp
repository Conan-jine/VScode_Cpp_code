#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct lis
{
    int index;
    int num;
}arr[1010];

bool cmp(lis q,lis p)
{
    return q.num<p.num;
};

int main()
{
    int n;
    double sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        arr[i].index=i+1;
        cin>>arr[i].num;
    }
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)
    {
        sum+=arr[i].num*(n-i-1);
    }
    cout<<arr[0].index;
    for(int i=1;i<n;i++)
    {
        cout<<' '<<arr[i].index;
    }
    cout<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum/n<<endl;
    return 0;
}