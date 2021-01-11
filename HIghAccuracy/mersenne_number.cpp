#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int num1[1010]={0},num2[1010]={0},sum[1010]={0};
int n;

void fun1()
{
    memset(num1,0,sizeof(sum));
    for(int i=1;i<=500;i++) for(int j=1;j<=500;j++) num1[i+j-1]+=num2[i]*sum[j];
    for(int i=1;i<=500;i++)
    {
        num1[i+1]+=num1[i]/10;
        num1[i]=num1[i]%10;
    }
    memcpy(sum,num1,sizeof(sum));
}

void fun2()
{
    memset(num1,0,sizeof(num1));
    for(int i=1;i<=500;i++) for(int j=1;j<=500;j++) num1[i+j-1]+=num2[i]*num2[j];
    for(int i=1;i<=500;i++)
    {
        num1[i+1]+=num1[i]/10;
        num1[i]=num1[i]%10;
    }
    memcpy(num2,num1,sizeof(num2));
}

int main()
{
    cin>>n;
    cout<<int(log10(2)*n+1)<<endl;
    sum[1]=1;
    num2[1]=2;
    while(n!=0)
    {
        if(n%2==1)  fun1();
        n>>=1;
        fun2();
    }
    sum[1]--;
    for(int i=500;i>=1;i--)
    {
        if(i!=500 && i%50==0)   cout<<endl;
        cout<<sum[i];
    }
    return 0;
}