#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue< int,vector<int>,greater<int> > q;
    int n,num,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        q.push(num);
    }
    while(q.size()!=1)
    {
        num=q.top();
        q.pop();
        num+=q.top();
        q.pop();
        sum+=num;
        q.push(num);
    }
    cout<<sum<<endl;
}
// 3 3+3+5+7
// 6 5+6+7
// 11 7+11
// 18