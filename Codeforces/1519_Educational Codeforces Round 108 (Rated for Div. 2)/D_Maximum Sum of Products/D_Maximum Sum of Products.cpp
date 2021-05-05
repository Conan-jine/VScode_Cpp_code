#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::reverse;

int arr1[5200];
int arr2[5200];
int temp2[5200];
unsigned long long int sum,maxsum;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr1[i];
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
        maxsum+=arr1[i]*arr2[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            sum=0;
            memcpy(temp2,arr1,sizeof(arr1));
            reverse(temp2+i,temp2+j);
            for(int m=0;m<n;m++)    sum+=arr2[m]*temp2[m];
            if(sum>maxsum)  maxsum=sum;
        }
    }
    cout<<maxsum<<endl;
    return 0;
}