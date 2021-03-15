#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n,k,arr[50];

bool dfs(int loc, int sum)
{
    if(loc==n)    return sum==k;
    if(dfs(loc+1, sum))   return true;
    if(dfs(loc+1, sum+arr[loc]))    return true;
    return false;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i];
    cin>>k;
    if(dfs(0,0))    cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;
    return 0;
}