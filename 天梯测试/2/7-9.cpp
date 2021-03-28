#include <iostream>
#include <algorithm>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

struct my_arr
{
    int loc=0;
    int send=0;
    int recive=0;
    int money=0;
}arr[10000];

bool cmp(my_arr a, my_arr b)
{
    if(a.money==b.money)
    {
        if(a.recive==b.recive)  return a.loc<b.loc;
        else    return a.recive>b.recive;
    }
    else    return a.money>b.money;
}

int main()
{
    int k,n,t;
    int sendM;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        arr[i].loc=i;
        cin>>k;
        arr[i].send=k;
        for(int j=0;j<k;j++)
        {
            cin>>t>>sendM;
            arr[t].money+=sendM;
            arr[i].money-=sendM;
            arr[t].recive+=1;
        }
    }
    std::sort(arr+1,arr+1+n,cmp);
    for(int i=1;i<=n;i++)   printf("%d %.2lf\n",arr[i].loc,double(arr[i].money)*0.01);
    return 0;
}