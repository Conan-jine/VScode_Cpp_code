#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

int n,arr[320];
unsigned long long sum=0;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i];
    sort(arr,arr+n);
    int right=n-1;
    int left=0;
    sum+=arr[right]*arr[right];
    while(right>left)
    {
        sum+=(arr[right]-arr[left])*(arr[right]-arr[left]);
        right--;
        sum+=(arr[left]-arr[right])*(arr[left]-arr[right]);
        left++;
    }
    cout<<sum<<endl;
    return 0;
}