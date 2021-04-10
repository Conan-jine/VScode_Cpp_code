#include <iostream>
#include <string>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string NUM;
int K,num;

bool judge(int n)
{
    int cnt=0;
    if(n==1 || n==0)    return false;
    if(n==2)    return true;
    for(int i=2;i*i<=n;i++) if(n%i==0)  cnt++;
    if(cnt==0)  return true;
    else    return false;
}

int myNum(int loc)
{
    int mNum=0;
    int c=1;
    for(int i=loc+K-1;i>=loc;i--)
    {
        mNum+=(NUM[i]-'0')*c;
        c*=10;
    }
    return mNum;
}

int main()
{
    int L;
    cin>>L>>K;
    cin>>NUM;
    for(int i=0;i<=L-K;i++)
    {
        if(judge(myNum(i)))
        {
            for(int j=i;j<i+K;j++)  cout<<NUM[j];
            // cout<<myNum(i)<<endl;
            return 0;
        }
    }
    cout<<404<<endl;
    return 0;
}