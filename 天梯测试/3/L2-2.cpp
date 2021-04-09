#include <iostream>
#include <algorithm>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct moon_cake
{
    double weight;
    double value;
    double rate;
}arr[1200];

bool cmp(moon_cake a, moon_cake b)
{
    return a.rate>b.rate;
}

int main()
{
    int n,need;
    double sum=0;
    cin>>n>>need;
    for(int i=0;i<n;i++)    cin>>arr[i].weight;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].value;
        arr[i].rate=arr[i].value/arr[i].weight;
    }
    sort(arr,arr+n,cmp);
    for(int i=0;i<n && need!=0;i++)
    {
        if(arr[i].weight<=need)
        {
            sum+=arr[i].value;
            need-=arr[i].weight;
        }
        else if(arr[i].weight>need)
        {
            sum+=need/arr[i].weight*arr[i].value;
            need=0;
        }
    }
    printf("%.2lf\n",sum);
    return 0;
}