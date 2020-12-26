#include <iostream>
#include <algorithm>
using namespace std;

struct segments
{
    int l,r;
}arr[10010];

bool cmp(segments a, segments b)
{
    if(a.l==b.l)    return a.r<b.r;
    else    return a.l<b.l;
}

int main()
{
    int num[10010]={0};
    int n,m,maxn=0;
    int i,j,k,start=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>num[i];
    for(int i=0;i<m;i++)    cin>>arr[i].l>>arr[i].r;
    sort(arr,arr+m,cmp);
    for(int k=0;k<n;k++)
    {
        maxn=0;
        for(i=0;i<n;i++)
        {
            for(j=start;j<m;j++)
            {
                if(num[i]<arr[j].l||num[i]>arr[j].r)    break;
            }
            if(j>maxn)  maxn=j;
        }
        start=maxn;
        if(start==m)    break;
    }
    if(k==n)    cout<<-1<<endl;
    else    cout<<k+1<<endl;
    return 0;
}