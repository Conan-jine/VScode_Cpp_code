#include <iostream>
#include <algorithm>
using namespace std;

struct game
{
    int l,r;
}arr[1000010];

bool cmp(game a,game b)
{
    return a.r<b.r;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i].l>>arr[i].r;
    sort(arr,arr+n,cmp);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i].l<<' '<<arr[i].r<<endl;
    // }
    int acgame=1;
    int a=0,b=1;
    while(b<n)
    {
        if(arr[a].r<=arr[b].l)
        {
            acgame++;
            a=b;
        }
        b++;
    }
    cout<<acgame<<endl;
    return 0;
}