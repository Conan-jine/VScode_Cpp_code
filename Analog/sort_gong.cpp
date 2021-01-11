#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct gong
{
    string name;
    int position;
    long long bgong;
    int level;
    int i;
}arr[120];

bool cmp1(gong a, gong b)
{
    if(a.bgong==b.bgong)    return a.i<b.i;
    else    return a.bgong>b.bgong;
}

bool cmp2(gong a, gong b)
{
    if(a.position==b.position)
    {
        if(a.level==b.level)    return a.i<b.i;
        else    return a.level>b.level;
    }
    else    return a.position<b.position;
}

int main()
{
    int n;
    string p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].name;
        cin>>p;
        if(p=="BangZhu")    arr[i].position=1;
        else if(p=="FuBangZhu") arr[i].position=2;
        else    arr[i].position=7;
        cin>>arr[i].bgong>>arr[i].level;
        arr[i].i=i;
    }
    std::sort(arr+3,arr+n,cmp1);
    int x=2,y=4,z=7,l=25,m=100;
    for(int i=0;i<n;i++)
    {
        if(i==0) arr[i].position=1;
		else if (i==1||i==2) arr[i].position=2;
		else if (i==3||i==4) arr[i].position=3;
		else if (i>=5&&i<=8) arr[i].position=4;
		else if (i>=9&&i<=15) arr[i].position=5;
		else if (i>=16&&i<=40) arr[i].position=6;
		else arr[i].position=7;
    }
    std::sort(arr+1,arr+n,cmp2);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].name<<' ';
        if(arr[i].position==1)  cout<<"BangZhu ";
        else if(arr[i].position==2) cout<<"FuBangZhu ";
        else if(arr[i].position==3) cout<<"HuFa ";
        else if(arr[i].position==4) cout<<"ZhangLao ";
        else if(arr[i].position==5) cout<<"TangZhu ";
        else if(arr[i].position==6) cout<<"JingYing ";
        else    cout<<"BangZhong ";
        cout<<arr[i].level<<endl;
    }
    return 0;
}