#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool judge(int n)
{
    if(n==2)    return true;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)  return false;
    }
    return true;
}

void fun(int t, int num)
{
    if(judge(num))
    {
        cout<<num<<endl<<t+1<<endl;
        return;
    }
    for(int i=2;i<=num/2;i++)
    {
        if(num%i==0&&judge(i))
        {
            cout<<i<<' ';
            fun(t+1,num/i);
            break;
        }
    }
}

int main()
{
    int num;
    cin>>num;
    fun(0,num);
    return 0;
}