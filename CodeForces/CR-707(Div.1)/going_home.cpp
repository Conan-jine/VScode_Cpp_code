#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::sort;

struct my_arr
{
    int num;
    int loc;
}arr[200020];

struct ano_arr
{
    bool exist=false;
    int loc1,loc2;
}sumArr[5000020];

int n,inx;

// bool cmp(my_arr a, my_arr b)
// {
//     return a.num<b.num;
// }

// bool binary_search(int x)
// {
//     int left=0,right=n;
//     int temp;
//     while(right-left>=1)
//     {
//         temp=(left+right)/2;
//         if(arr[temp].num==x)
//         {
//             inx=arr[temp].loc;
//             return true;
//         }
//         else if(arr[temp].num>x) right=temp;
//         else    left=temp+1;
//     }
//     return false;
// }

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].num;
        arr[i].loc=i+1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sumArr[arr[i].num+arr[j].num].exist=true;
            sumArr[arr[i].num+arr[j].num].loc1=arr[i].loc;
            sumArr[arr[i].num+arr[j].num].loc2=arr[j].loc;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            inx=arr[i].num+arr[j].num;
            if(sumArr[inx].exist)
            {
                if(arr[i].loc!=sumArr[inx].loc1 && arr[j].loc!=sumArr[inx].loc2 && arr[i].loc!=sumArr[inx].loc2 && arr[j].loc!=sumArr[inx].loc1)
                {
                    cout<<"YES"<<endl;
                    cout<<arr[i].loc<<' '<<arr[j].loc<<' '<<sumArr[inx].loc1<<' '<<sumArr[inx].loc2<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}