#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Students
{
    string rollnum;
    string name;
    double subject1_marks;
    double subject2_marks;
    double subject3_marks;
    double subject4_marks;
    double subject5_marks;
    int sumFailed=0;
    double sumofMarks=0;
};

bool cmp1(Students a, Students b);
bool cmp2(Students a, Students b);
bool cmp3(Students a, Students b);
bool cmp4(Students a, Students b);
bool cmp5(Students a, Students b);
bool cmpFailed(Students a, Students b);
bool cmpSum(Students a, Students b);

int main()
{
    Students stu[5];
    cout<<"Please enter 5 students information: "<<endl;
    // 输入5个学生的信息
    for(int i=0;i<5;i++)
    {
        cout<<"student "<<i+1<<':'<<endl;
        cout<<"\trollno: ";
        cin>>stu[i].rollnum;
        cout<<"\tname: ";
        cin>>stu[i].name;
        cout<<"\tFive subject scores(Enter in one line): ";
        cin>>stu[i].subject1_marks
           >>stu[i].subject2_marks
           >>stu[i].subject3_marks
           >>stu[i].subject4_marks
           >>stu[i].subject5_marks;
        // 其实可以写成一行，我写成5行好看一点，上面同理
        stu[i].sumofMarks+=stu[i].subject1_marks;
        stu[i].sumofMarks+=stu[i].subject2_marks;
        stu[i].sumofMarks+=stu[i].subject3_marks;
        stu[i].sumofMarks+=stu[i].subject4_marks;
        stu[i].sumofMarks+=stu[i].subject5_marks;

        // 判断是否挂科 failed，挂科数目进行统计
        if(stu[i].subject1_marks<60)    stu[i].sumFailed++;
        if(stu[i].subject2_marks<60)    stu[i].sumFailed++;
        if(stu[i].subject3_marks<60)    stu[i].sumFailed++;
        if(stu[i].subject4_marks<60)    stu[i].sumFailed++;
        if(stu[i].subject5_marks<60)    stu[i].sumFailed++;
    }

    // 使用sort函数对总分进行排序,特别的,需要使用cmp；
    // 分别排序然后分别输出排序后的情况,这里我只演示总分的
    // 其他科目的同理，不懂的话再联系我，我补代码，我就是觉得代码太长了有点那啥
    cout<<endl<<endl<<"Rank of SumMarks:"<<endl;
    sort(stu,stu+5,cmpSum);
    for(int i=0;i<5;i++)
    {
        cout<<"rollno="<<stu[i].rollnum<<'\t'
            <<"name="<<stu[i].name<<'\t'
            <<"sumScores="<<stu[i].sumofMarks<<endl;
    }

    // 根据 挂科数目进行排序并输出名字可挂科数
    cout<<endl<<endl<<"Rank of Failednumbers:"<<endl;
    sort(stu,stu+5,cmpFailed);
    for(int i=0;i<5;i++)
    {
        if(stu[i].sumFailed>1)
        {
            cout<<"name="<<stu[i].name<<'\t'
                <<"failednumers="<<stu[i].sumFailed<<endl;
        }
    }
    return 0;
}

bool cmp1(Students a, Students b)
{
    return a.subject1_marks>b.subject1_marks;
}

bool cmp2(Students a, Students b)
{
    return a.subject2_marks>b.subject2_marks;
}

bool cmp3(Students a, Students b)
{
    return a.subject3_marks>b.subject3_marks;
}

bool cmp4(Students a, Students b)
{
    return a.subject4_marks>b.subject4_marks;
}

bool cmp5(Students a, Students b)
{
    return a.subject5_marks>b.subject5_marks;
}

bool cmpFailed(Students a, Students b)
{
    return a.sumFailed>b.sumFailed;
}

bool cmpSum(Students a, Students b)
{
    return a.sumofMarks>b.sumofMarks;
}

