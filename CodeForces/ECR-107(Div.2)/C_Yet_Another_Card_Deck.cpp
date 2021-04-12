#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int arr[660000];

int main()
{
    int n,times,temp,loc;
    cin>>n>>times;
    for(int i=n;i>0;i--)    cin>>arr[i];
    while(times--)
    {
        cin>>temp;
        loc=n;
        for(int i=n;i>0;i--)
        {
            if(arr[i]==0)   continue;
            loc--;  
            if(arr[i]==temp) 
            {
                n=n+1;
                arr[n]=temp;
                arr[i]=0;
                cout<<n-loc-1<<endl;
                break;
            }
        }
    }
    return 0;
}