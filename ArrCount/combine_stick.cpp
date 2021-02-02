#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int arr[5200];
long long K=1000000007LL;

long long C(long long cnt, long long num)
{
    return num==1LL ? cnt : cnt*(cnt-1)/2;
}

int main()
{
    int n,temp,maxNum=0;
    unsigned long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr[temp]++;
        maxNum=temp > maxNum ? temp : maxNum;
    }
    for(int i=maxNum;i>0;i--)
    {
        if(arr[i]<2)    continue;
        for(int j=1;j<=i/2;j++)
        {
            if(arr[j] && arr[i-j])
            {
                if(j==i-j)  sum+=C(arr[i],2)%K*C(arr[j],2)%K;
                else    sum+=C(arr[i],2)%K*C(arr[j],1)*C(arr[i-j],1);
                sum%=K;
                // cout<<i<<' '<<j<<' '<<i-j<<endl;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}