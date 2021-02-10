#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

void output(int num)
{
    int i=0;
    while(num!=0)
    {
        i=0;
        while(num>=pow(2,i)) i++;
        if(i!=0)    i--;
        num-=pow(2,i);
        if(i==0)
        {
            cout<<"2(0)";
            if(num!=0)  cout<<'+';
            continue;
        }
        if(i==1)
        {
            cout<<"2";
            if(num!=0)  cout<<'+';
            continue;
        }
        cout<<"2(";
        output(i);
        cout<<")";
        if(num!=0)  cout<<'+';
    }
}

int main()
{
    int num;
    cin>>num;
    output(num);
    return 0;
}