#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

long long int arr[1001000];
long long int n,m;

int main()
{
    int temp;
    int maxNum=0;
    long long int cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>maxNum)   maxNum=arr[i];
    }
    int left=0,right=maxNum;
    while(right-left>=0)
    {
        temp=(left+right)/2;
        cnt=0;
        for(int i=0;i<n;i++)    if(arr[i]>temp) cnt+=arr[i]-temp;
        if(cnt>=m)   left=temp+1;
        else    right=temp-1;
    }
    cout<<left-1<<endl;
    return 0;
}