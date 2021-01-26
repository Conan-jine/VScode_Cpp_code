#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    unsigned long long num;
    cin>>n;
    while(n--)
    {
        cin>>num;
        if(num%2==1)    cout<<"YES"<<endl;
        else
        {
            while(num%2==0) num/=2;
            if(num==1)  cout<<"NO"<<endl;
            else    cout<<"YES"<<endl;
        }
    }
}