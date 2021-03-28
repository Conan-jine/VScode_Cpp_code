#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

const int INF=100000000;
int n,arr[120];

int main()
{
    int i,j,t,cost=0,minNum,loc;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cost=0;
        cin>>n;
        for(int i=1;i<=n;i++)   cin>>arr[i];
        for(int i=1;i<n;i++)
        {
            minNum=INF;
            for(j=i;j<=n;j++)
            {
                if(arr[j]<minNum)
                {
                    minNum=arr[j];
                    loc=j;
                }
            }
            std::reverse(arr+i,arr+loc+1);
            // for(int i=1;i<=n;i++)   cout<<arr[i]<<' ';
            // cout<<endl;
            cost+=loc-i+1;
        }
        cout<<"Case #"<<k<<": "<<cost<<endl;
    }   
    return 0;
}