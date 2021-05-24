#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int big,one,two,three,n;
    while(cin>>n)
    {
        if(n==0)    break;
        big=1;
        one=two=three=0;
        n--;
        while(n--)
        {
            big+=three;
            three=two;
            two=one;
            one=big;
        }
        cout<<big+three+two+one<<endl;
    }
    return 0;
}