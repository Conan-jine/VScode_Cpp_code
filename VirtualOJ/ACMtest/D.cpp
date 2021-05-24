#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int t,n;
    int arr[120];
    int minnum,cnt;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        minnum=100000;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]<minnum)   minnum=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>minnum)   cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}