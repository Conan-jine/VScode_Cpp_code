#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool judge=false;
    int n;
    double sum=0,avg=0,arr[1100]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    avg=sum/n;
    for(int i=0;i<n;i++)
    {
        if(fabs(arr[i])>avg)
        {
            if(judge)   cout<<' ';
            cout<<arr[i];
            judge=true;
        }
    }
    return 0;
}