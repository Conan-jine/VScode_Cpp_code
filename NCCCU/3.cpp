#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Stu
{
    string name;
    string noll;
    double GPA;
    double addS;
    string scn;
};

bool cmpGPA(Stu a, Stu b)
{
    return a.GPA>b.GPA;
}

bool cmpaddS(Stu a, Stu b)
{
    return a.addS>b.addS;
}

bool cmpGPAandaddS(Stu a, Stu b)
{
    return a.GPA+a.addS > b.GPA+b.addS;
}

int main()
{
    int n,m;
    Stu stu[1100];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>stu[i].name;
        cin>>stu[i].noll;
        cin>>stu[i].GPA;
        cin>>stu[i].addS;
        cin>>stu[i].scn;
    }
    sort(stu,stu+n,cmpGPA);
    for(int i=0;i<m;i++)
    {
        if(i!=0)    cout<<' ';
        cout<<stu[i].scn;
    }
    cout<<endl;

    sort(stu,stu+n,cmpaddS);
    for(int i=0;i<m;i++)
    {
        if(i!=0)    cout<<' ';
        cout<<stu[i].noll;
    }
    cout<<endl;

    sort(stu,stu+n,cmpGPAandaddS);
    for(int i=0;i<m;i++)
    {
        if(i!=0)    cout<<' ';
        cout<<stu[i].name;
    }
    return 0;
}