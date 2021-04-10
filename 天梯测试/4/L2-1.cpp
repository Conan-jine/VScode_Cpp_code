#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;

stack<int> M;

int mlen,nlen,times;
int arr[1110];

int main()
{
    int temp,num,loc=0;
    cin>>mlen>>nlen>>times;
    while(times--)
    {
        while(!M.empty())   M.pop();
        for(int i=0;i<nlen;i++) cin>>arr[i];
        num=1;
        loc=0;
        while(1)
        {
            if(M.empty() || M.top()!=arr[loc])  M.push(num++);
            temp=M.size();
            if(temp>mlen || M.top()==nlen+1)
            {
                cout<<"NO"<<endl;
                break;
            }
            if(M.top()==arr[loc] && loc==nlen-1)
            {
                cout<<"YES"<<endl;
                break;
            }
            if(M.top()==arr[loc])
            {
                M.pop();
                loc++;
            }
        }
    }
    return 0;
}