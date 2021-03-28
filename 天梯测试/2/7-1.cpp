#include <iostream>
#include <string>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string num;
    cin>>num;
    int len;
    double cntTwo=0;
    bool negative=false,even=false;
    len=num.length();
    for(int i=0;i<len;i++)  if(num[i]=='2') cntTwo=cntTwo+1;
    if((num[len-1]-'0')%2==0)   even=true;
    if(num[0]=='-')
    {
        negative=true;
        len--;
    }
    double res=1;
    res=cntTwo/len;
    if(negative)    res*=1.5;
    if(even)    res*=2;
    printf("%.2lf%%",res*100);
    return 0;
}