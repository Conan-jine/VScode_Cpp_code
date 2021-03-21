#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void output(int num)
{
    if(num<10)  cout<<'0';
    cout<<num;
}

int main()
{
    int h,m;
    char c;
    cin>>h>>c>>m;
    if(h<12 || (h==12 && m==0))
    {
        cout<<"Only ";
        output(h);
        cout<<":";
        output(m);
        cout<<".  Too early to Dang."<<endl;
    }
    else
    {
        if(m!=0)    h++;
        h-=12;
        for(int i=0;i<h;i++)    cout<<"Dang";
        cout<<endl;
    }
    return 0;
}