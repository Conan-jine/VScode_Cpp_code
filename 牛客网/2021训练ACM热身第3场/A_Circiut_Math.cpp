#include <iostream>
#include <queue>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::queue;

char c,a,b;
stack<char> countChar;
queue<char> realMean;
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        realMean.push(c);
    }
    while(cin>>c)
    {
        if(c!='*' && c!='+' && c!='-')
        {
            c=realMean.front();
            realMean.pop();
            countChar.push(c);
        }
        else if(c=='*')
        {
            a=countChar.top();
            countChar.pop();
            b=countChar.top();
            countChar.pop();
            if(a!=b)    countChar.push('F');
            else    countChar.push(a);
        }
        else if(c=='+')
        {
            a=countChar.top();
            countChar.pop();
            b=countChar.top();
            countChar.pop();
            if(a=='T' || b=='T')    countChar.push('T');
            else    countChar.push('F');
        }
        else if(c=='-')
        {
            a=countChar.top();
            countChar.pop();
            if(a=='T')  countChar.push('F');
            else    countChar.push('T');
        }
    }
    cout<<countChar.top()<<endl;
    return 0;
}