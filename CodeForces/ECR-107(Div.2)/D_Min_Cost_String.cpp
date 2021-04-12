#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n,k,loc=0,need,m;
    int arr[700];
    int add[2]={1,1};
    cin>>n>>k;
    if(k==1)
    {
        for(int i=0;i<n;i++)    cout<<'a';
        return 0;
    }
    for(int i=0;i<k-1;i++)
    {
        add[0]=i+1;
        add[1]=i+1;
        for(int j=0;j<k-i-1;j++)
        {
            arr[loc]=add[0]+j;
            arr[loc+1]=add[1];
            loc+=2;
        }
        arr[loc++]=k;
    }
    arr[loc++]=k;
    arr[loc]=1;
    need=k*k;
    m=n;
    // for-loop print can overwrite in other greate way
    for(loc=0;loc<n;loc++)
    {
        cout<<char(arr[loc]+'a'-1);
        need--;
        if(need==0 && loc!=n-1)
        {
            loc=-1;
            need=k*k;
            n-=k*k;
        }
    }
    return 0;
}
// 1=11 2
// 2=11221 5
// 3=1121322331 10
// 4=11213142232433441 17
// 5=11213141522324253343544551 26