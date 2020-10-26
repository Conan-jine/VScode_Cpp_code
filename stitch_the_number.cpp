#include <iostream>
#include <algorithm>
#include <string>
using namespace std;        // not done.

bool cmp(string a, string b)
{
    return a+b>b+a;
}

int main()
{
    int n;
    string temp,arr[23];
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i];
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;i++)    cout<<arr[i];
    return 0;
}