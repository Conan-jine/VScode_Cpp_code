#include <iostream>
using namespace std;

int main()
{
    // 因为一些原因，我只能用Pi来表示圆周率，
    // 如果打印（cout）题目要求的“Π”会很麻烦，
    // 最直接的体现就是程序输出“Π”将会是乱码，这将涉及到。
    int i=1,n,a=3;
    cout<<"Please input a number: ";
    cin>>n;
    cout<<"\tPi/4=1";
    while(i<=n-1)
    {
        if(i%2==1)  cout<<'-';
        else    cout<<'+';
        cout<<"1/"<<a;
        a+=2;
        i++;
    }
    return 0;
}