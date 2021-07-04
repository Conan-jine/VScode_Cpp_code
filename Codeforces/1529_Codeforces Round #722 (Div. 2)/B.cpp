#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

int arr[100010];
int plusArr[100010];
int t, n;
int minNum, deleteLen;
int arrPtr, plusPtr;

int main()
{
    cin>>t;
    while(t--)
    {
        arrPtr=plusPtr=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[arrPtr];
            if(arr[arrPtr]>0)    plusArr[plusPtr++]=arr[arrPtr--];
            arrPtr++;
        }
        // sort(arr, arr+n);
        minNum=1111111111;
        if(plusPtr==n)
        {
            cout<<1<<endl;
            continue;
        }
        sort(arr, arr+arrPtr);
        for(int i=0;i<arrPtr-1;i++)
        {
            if(minNum==1)   break;
            if(abs(arr[i+1]-arr[i])<minNum)  minNum=abs(arr[i+1]-arr[i]);
        }
        for(int i=0;i<plusPtr;i++)
        {
            if(plusArr[i]>minNum || plusArr[i+1]==plusArr[i]&&i<plusPtr-1)   n--;
        }
        cout<<n<<endl;
    }
    return 0;
}