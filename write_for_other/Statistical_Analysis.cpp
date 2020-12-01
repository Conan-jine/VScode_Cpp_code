#include <iostream>
using namespace std;

int main()
{
    int lenOfArr=0,index=0;
    double arr[100000]={0},modenum[1000]={0};
    double sum=0,median=0,maxlen=1,temp=1;
    double averageOfArr=0;
    cout<<"Please input the lenght of a set of numbers: ";
    cin>>lenOfArr;
    cout<<"Please input the numbers:"<<endl;
    for(int i=1;i<=lenOfArr;i++)
    {
        cin>>arr[i];
        sum+=arr[i]; //sum=sum+arr[i] 的简写
        // 统计相同数字出现的最高次数
        if(arr[i]==arr[i-1])
        {
            temp++;
        }
        else
        {
            if(temp>maxlen)
            {
                maxlen=temp;
                temp=1;
            }
        }
    }
    cout<<endl;
    // 计算平均值
    averageOfArr=sum/lenOfArr;
    // 获得中位数
    if(lenOfArr%2==0)
    {
        median=(arr[lenOfArr/2]+arr[lenOfArr/2+1])/2;
    }
    else
    {
        median=arr[lenOfArr/2];
    }
    // 获取众数，众数可能有多个
    temp=1;
    for(int i=1;i<=lenOfArr;i++)
    {
        if(arr[i]==arr[i-1])
        {
            temp++;
        }
        else
        {
            if(temp==maxlen)
            {
                modenum[index]=arr[i-1];
                index++;
                temp=1;
            }
        }
    }
    //输出三数
    cout<<"mean = "<<averageOfArr<<endl;
    cout<<"median = "<<median<<endl;
    cout<<"mode number:";
    for(int i=0;i<index;i++)
    {
        cout<<"  "<<modenum[i];
    }
    return 0;
}