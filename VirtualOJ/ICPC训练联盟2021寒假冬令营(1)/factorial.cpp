#include <iostream>
using std::cin;
using std::cout;
using std::endl;

unsigned long long dp[14]={0};

int main()
{
    dp[0]=1;
    int n,it=0;
    for(int i=1;i<14;i++)   dp[i]=i*dp[i-1];
    while(cin>>n)
    {
        if(n>13)
        {
            cout<<"Overflow!"<<endl;
            continue;
        }
        else if(n<8 && n>=0)
        {
            cout<<"Underflow!"<<endl;
            continue;
        }
        else if(n<0)
        {
            n=-n;
            if(n%2==0)  cout<<"Underflow!"<<endl;
            else    cout<<"Overflow!"<<endl;
            continue;
        }
        else
        {
            cout<<dp[n]<<endl;
            continue;
        }
    }
}