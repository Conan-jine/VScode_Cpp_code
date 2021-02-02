#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int sum=0,sumArr=0;

void input(int *arr, int len)
{
    sumArr=0;
    for(int i=1;i<=len;i++)
    {
        cin>>arr[i];
        sumArr+=arr[i];
    }
}

int dp(int arr[], int len)
{
    int res[1250]={0};
    for(int i=1;i<=len;i++)
    {
        for(int j=sumArr/2;j>=arr[i];j--)
        {
            res[j]=res[j] > res[j-arr[i]]+arr[i] ? res[j] : res[j-arr[i]]+arr[i]; 
        }
    }
    return sumArr-res[sumArr/2] > res[sumArr/2] ? sumArr-res[sumArr/2] : res[sumArr/2];
}

int main()
{
    int n1,n2,n3,n4,arr[25];
    cin>>n1>>n2>>n3>>n4;
    input(arr,n1);
    sum+=dp(arr,n1);
    input(arr,n2);
    sum+=dp(arr,n2);
    input(arr,n3);
    sum+=dp(arr,n3);
    input(arr,n4);
    sum+=dp(arr,n4);
    cout<<sum<<endl;
    return 0;
}