#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    int a,b;
    int arr[100010];
    while(cin>>n)
    {
        if(n==0)    break;
        memset(arr,0,sizeof(arr));
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b;
            arr[a]++;
            arr[b+1]--;
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=1)    cout<<' ';
            arr[i]+=arr[i-1];
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}