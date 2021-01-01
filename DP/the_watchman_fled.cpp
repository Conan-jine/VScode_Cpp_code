#include <iostream>
using namespace std;

struct dp
{
    int m,s1,s2,t;
};

dp arr[300010]={0};

int main()
{
    
    int M,S,T;
    cin>>M>>S>>T;
    arr[1].m=M;
    arr[0].s1=0;
    arr[0].s2=0;
    arr[0].t=0;
    for(int i=1;i<=T;i++)
    {
        if(arr[i].m>9)
        {
            arr[i].s1=arr[i-1].s1+60;
            arr[i+1].m=arr[i].m-10;
            arr[i].t=arr[i-1].t+1;
        }
        else
        {
            arr[i].s1=arr[i-1].s1;
            arr[i+1].m=arr[i].m+4;
            arr[i].t=arr[i-1].t+1;
        }
        arr[i].s2=arr[i-1].s2+17 > arr[i].s1 ? arr[i-1].s2+17 : arr[i].s1;
        // cout<<arr[i].s2<<' '<<arr[i].t<<endl;
        if(arr[i].s2>=S)
        {
            cout<<"Yes"<<endl<<arr[i].t<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl<<arr[T].s2<<endl;
    return 0;
}