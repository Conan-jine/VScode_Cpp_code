#include <iostream>
#include <queue>
#include <stack>
using namespace std;
stack <int> num;

int main()
{
    int n=0,a,b;
    char c;
    while(cin>>c)
    {
        if(c=='@')  break;
        if(c=='-')
        {
            b=num.top();
            num.pop();
            a=num.top();
            num.pop();
            num.push(a-b);
        }
        else if(c=='+')
        {
            b=num.top();
            num.pop();
            a=num.top();
            num.pop();
            num.push(a+b);
        }
        else if(c=='/')
        {
            b=num.top();
            num.pop();
            a=num.top();
            num.pop();
            num.push(a/b);
        }
        else if(c=='*')
        {
            b=num.top();
            num.pop();
            a=num.top();
            num.pop();
            num.push(a*b);
        }
        else if(c=='.')
        {
            num.push(n);
            n=0;
        }
        else
        {
            n*=10;
            n+=int(c-'0');
        }
        
    }
    cout<<num.top()<<endl;
}