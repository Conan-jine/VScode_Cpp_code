#include <iostream>
#include <algorithm>
using namespace std;

int *arr;

int main()
{
    int n,MAX;
    cin>>MAX>>n;
    arr=new int [n];
    for(int i=0;i<n;i++)    cin>>arr[i];
    sort(arr,arr+n);
    int sum=0;
    int i,j;
    i=0;
    j=n-1;
    while(i<=j)
    {
        if(arr[j]+arr[i]>MAX || arr[j]==MAX)
        {
            sum++;
            j--;
        }
        else if(arr[j]+arr[i]<=MAX || i==j)
        {
            sum++;
            i++;
            j--;
        }
    }
    cout<<sum<<endl;
    return 0;
}