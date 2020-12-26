#include <iostream>
using namespace std;

int main()
{
    bool jd=true;
    int sum=0,n,arr[110],t=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sum/=n;
    for(int i=0;i<n;i++)    arr[i]-=sum;
    for(int i=0;i<n;i++)
    {
        if(jd&&arr[i]==0)   continue;
        else
        {
            arr[i+1]+=arr[i];
            t++;
            jd=false;
            if(arr[i+1]==0) jd=true;
        }
        
    }
    cout<<t<<endl;
}