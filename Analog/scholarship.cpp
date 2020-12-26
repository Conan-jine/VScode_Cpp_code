#include <iostream>
using namespace std;

struct student
{
    int num;
    int chinese;
    int math;
    int english;
    int sum;
};

void fun(student *arr1,student *arr2)
{
    student temp;
    temp=*arr1;
    *arr1=*arr2;
    *arr2=temp;
}

int main()
{
    int n;
    cin>>n;
    student stu[310];
    for(int i=0;i<n;i++)
    {
        cin>>stu[i].chinese;
        cin>>stu[i].math;
        cin>>stu[i].english;
        stu[i].num=i+1;
        stu[i].sum=stu[i].chinese+stu[i].math+stu[i].english;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(stu[j].sum<stu[j+1].sum) fun(&stu[j],&stu[j+1]);
            else if(stu[j].sum==stu[j+1].sum&&stu[j].chinese<stu[j+1].chinese)  fun(&stu[j],&stu[j+1]);
            else if(stu[j].sum==stu[j+1].sum&&stu[j].chinese==stu[j+1].chinese&&stu[j].num>stu[j+1].sum)    fun(&stu[j],&stu[j+1]);
        }
    }
    for(int i=0;i<5&&i<n;i++)
    {
        cout<<stu[i].num<<' '<<stu[i].sum<<endl;
    }
    return 0;
}