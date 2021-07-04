#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

int times;
int n,k,l;
int arr[250000];

int main()
{
    cin>>times;
    while(times--)
    {
        cin>>n;
        k=0;
        for(int i=0;i<n;i++)    cin>>arr[i];
        sort(arr, arr+n);
        for(int i=0;i<n;i++)
        {
            if(arr[i]==arr[i+1])
            {
                k=arr[i];
                arr[i]-=k;
                arr[i+1]-=k;
            }   
        }
        l=arr[1];
        if(k!=0)    cout<<k;
        else
        {
            cout<<arr[0];
            arr[1]=0;
            arr[0]=0;
        }
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            while(arr[j]==0)   j--;
            while(arr[i]==0)   i++;
            if(i==j)    cout<<' '<<arr[j];
            else if(i<j)    cout<<' '<<arr[j]<<' '<<arr[i];
        }
        if(k!=0)    cout<<' '<<k<<endl;
        else    cout<<' '<<l<<endl;
    }
    return 0;
}