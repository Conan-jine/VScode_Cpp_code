#include <iostream>
#include <algorithm>
#include <string>

struct cards
{
    int num;
    std::string name;
    int money;
    int up;
}arr[15];

bool cmp1(cards a, cards b)
{
    if(a.up==b.up)  return a.money<b.money;
    else    return a.up>b.up;
}

bool cmp2(cards a, cards b)
{
    return a.num<b.num;
}

int main()
{
    int n,allm;
    std::cin>>n>>allm;
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i].name>>arr[i].money>>arr[i].up;
        arr[i].num=i;
    }
    std::sort(arr,arr+n,cmp1);
    for(int i=0;i<n;i++)
    {
        allm-=arr[i].money;
        if(allm<0)  arr[i].up=0;
    }
    std::sort(arr,arr+n,cmp2);
    for(int i=0;i<n;i++)
    {
        std::cout<<arr[i].name<<' '<<arr[i].money<<' '<<arr[i].up<<std::endl;
    }
    return 0;
}