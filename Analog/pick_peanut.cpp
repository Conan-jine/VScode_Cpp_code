#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

struct point
{
    int x,y,num;
}arr[1010];

bool cmp(point a, point b)
{
    return a.num>b.num;
}

int main()
{
    int len=0,m,n,k,sum=0;
    int x,y,num;
    cin>>m>>n>>k;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>num;
            if(num!=0)
            {
                arr[len].x=i+1;
                arr[len].y=j+1;
                arr[len].num=num;
                len++;
            }
        }
    }
    std::sort(arr,arr+len,cmp);
    int lx=0,ly=arr[0].y;
    for(int i=0;i<len;i++)
    {
        if(k-(abs(arr[i].x-lx)+abs(arr[i].y-ly)+arr[i].x+1)>=0)
        {
            sum+=arr[i].num;
            k-=(abs(arr[i].x-lx)+abs(arr[i].y-ly));
            k--;
            lx=arr[i].x;
            ly=arr[i].y;
            // cout<<"k="<<k<<endl;
        }
        else    break;
    }
    cout<<sum<<endl;
}