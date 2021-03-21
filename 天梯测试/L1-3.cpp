#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string stander;
string num1,num2;
int sum[22],numStander[22];

int main()
{
    int len;
    cin>>stander>>num1>>num2;
    if(num1.size()<num2.size()) swap(num1,num2);
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    reverse(stander.begin(),stander.end());
    len=num1.size()-num2.size();
    for(int i=0;i<=len;i++)  num2+='0';
    // cout<<num1<<endl<<num2<<endl<<stander<<endl;
    len=stander.size();
    for(int i=0;i<len;i++)   numStander[i]=stander[i]-'0';
    len=num1.size();
    for(int i=0;i<len;i++)  sum[i]=num1[i]-'0'+num2[i]-'0';
    for(int i=0;i<22;i++)
    {
        if(sum[i]>=numStander[i])
        {
            if(numStander[i]==0)
            {
                sum[i+1]+=sum[i]/10;
                sum[i]%=10;
            }
            else
            {
                sum[i+1]+=sum[i]/numStander[i];
                sum[i]%=numStander[i];
            }
            
        }
    }
    bool judge=false;
    for(int i=21;i>=0;i--)
    {
        if(sum[i]!=0)   judge=true;
        if(judge)   cout<<sum[i];
    }
    if(!judge)  cout<<0<<endl;
    return 0;
}