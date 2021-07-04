#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

double arr[110];
int ptrEnd;
int arrLen;
double a,b;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<n;i++)    cin>>arr[i];
        std::sort(arr,arr+n);
        a=arr[0];
        b=arr[1];
        arrLen=0;
        ptrEnd=n-1;
        while( (a+b+arr[ptrEnd])/3 < arr[ptrEnd])
        {
            arrLen++;
            ptrEnd--;
        }
        cout<<arrLen<<endl;
    }
    return 0;
}