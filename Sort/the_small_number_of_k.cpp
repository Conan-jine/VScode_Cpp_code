#include <iostream>
#include <cstdio>
using namespace std;

int k;
int arr[5000010];

void qsort(int l,int r)
{
    int i=l,j=r,mid=arr[(l+r)/2];
    while(i<=j)
    {
        while(arr[i]<mid)   i++;
        while(arr[j]>mid)   j--;
        if(i<=j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(k<=j)    qsort(l,j);
    else if(k>=i)   qsort(i,r);
    else cout<<arr[i-1];
}

int main()
{
    int n;
    cin>>n>>k;
    for(int i=0;i<n;i++)    scanf("%d",&arr[i]);
    qsort(0,n-1);
    return 0;
}