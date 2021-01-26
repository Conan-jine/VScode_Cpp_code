#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/* 
    本题主要是判断加排序
    判断结构体的数据合理性
    排序结构体时间总和
*/

struct Team
{
    string name;
    int submitTimes[5];
    int solvTime[5];
    int sumSolv;
    int sumTime;
}arr[4000];

bool cmp(Team a, Team b)
{
    if(a.sumSolv==b.sumSolv)    return a.sumTime<b.sumTime;
    else    return a.sumSolv>b.sumSolv;
}

int main()
{
    int n;
    cin>>n;
    // 读入数据和处理数据一起做
    for(int i=0;i<n;i++)
    {
        arr[i].sumSolv=0;
        arr[i].sumTime=0;
        cin>>arr[i].name;
        for(int j=0;j<4;j++)
        {
            cin>>arr[i].submitTimes[j]>>arr[i].solvTime[j];
            if(arr[i].solvTime[j]!=0)
            {
                arr[i].sumSolv++;
                arr[i].sumTime+=arr[i].solvTime[j]+(arr[i].submitTimes[j]-1)*20;
            }
        }
    }
    std::sort(arr,arr+n,cmp);
    cout<<arr[0].name<<' '<<arr[0].sumSolv<<' '<<arr[0].sumTime<<endl;
    return 0;
}