#include <iostream>
#include <string>
using namespace std;

struct stu
{
    string name;
    int year;
    int month;
    int day;
    int lnum;
};

int main()
{
    int n;
    cin>>n;
    stu arr[110];
    for(int i=0;i<n;i++)    cin>>arr[i].name>>arr[i].year>>arr[i].month>>arr[i].day;
    for(int i=0;i<n;i++)    arr[i].lnum=i;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j].year>arr[j+1].year)   swap(arr[j],arr[j+1]);
            else if(arr[j].year==arr[j+1].year)
            {
                if(arr[j].month>arr[j+1].month) swap(arr[j],arr[j+1]);
                else if(arr[j].month==arr[j+1].month)
                {
                    if(arr[j].day>arr[j+1].day)    swap(arr[j],arr[j+1]);
                    else if(arr[j].day==arr[j+1].day)
                    {
                        if(arr[j].lnum<arr[j+1].lnum)   swap(arr[i],arr[j+1]);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)    cout<<arr[i].name<<endl;
}